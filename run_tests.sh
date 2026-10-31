#!/usr/bin/env bash
# Использование:  ./run_tests.sh ./путь/к/вашему_парсеру [-v]
#   ok   — программа ДОЛЖНА разобраться (парсер печатает "Good", код возврата 0)
#   bad  — программа ДОЛЖНА дать синтаксическую ошибку (код возврата != 0)
#   todo — пока не поддерживается: падение не считается ошибкой, но если
#          внезапно заработало — скрипт сообщит об этом
BIN="${1:?Укажите путь к собранному парсеру, например: ./run_tests.sh ./odin}"
VERBOSE="$2"
if [[ ! -x "$BIN" && ! -x "$BIN.exe" ]]; then
    echo "ОШИБКА: парсер '$BIN' не найден. Сначала соберите его:"
    echo "  bison -d -v parser.y && flex lexer.l && gcc parser.tab.c lex.yy.c -o odin"
    exit 2
fi
TMP="$(mktemp -d)"; trap 'rm -rf "$TMP"' EXIT
pass=0; fail=0; todo_fail=0; todo_pass=0; FAILED=(); NOWOK=()

run() {  # $1=ok|bad|todo  $2=имя ; код программы приходит из stdin
    local kind="$1" name="$2" f="$TMP/t.odin"
    cat > "$f"
    local out rc
    out="$(timeout 10 "$BIN" "$f" 2>&1)"; rc=$?
    local good=0; [[ $rc -eq 0 && "$out" == *Good* ]] && good=1
    case "$kind" in
      ok)   if [[ $good -eq 1 ]]; then ((pass++)); else ((fail++)); FAILED+=("ok   $name :: $(echo "$out" | head -1)"); fi ;;
      bad)  if [[ $good -eq 0 && $rc -ne 124 && $rc -ne 126 && $rc -ne 127 ]]; then ((pass++)); else ((fail++)); FAILED+=("bad  $name :: парсер принял неверную программу"); fi ;;
      todo) if [[ $good -eq 1 ]]; then ((todo_pass++)); NOWOK+=("$name"); else ((todo_fail++)); fi ;;
    esac
    [[ -n "$VERBOSE" ]] && printf '%-5s %-34s rc=%s %s\n' "$kind" "$name" "$rc" "$(echo "$out" | head -1)"
}
ok(){ run ok "$1"; }; bad(){ run bad "$1"; }; todo(){ run todo "$1"; }

############################ БАЗА ############################
ok "basic/hello" <<'EOF'
package main
import "core:fmt"
main :: proc() {
	fmt.println("hi")
}
EOF
ok "basic/consts" <<'EOF'
package main
MAX :: 100
NAME :: "x"
PI :: 3.14
C: int : 100
D, E, F: f32 : 1.0, 2.0, 3.0
EOF
ok "basic/vars" <<'EOF'
package main
x: int = 5
y: int
z := 1
a, b := 1, 2
EOF
ok "basic/proc-params-return" <<'EOF'
package main
add :: proc(a: int, b: int) -> int {
	return a + b
}
pair :: proc() -> (int, int) {
	return 1, 2
}
sum :: proc(a, b: int) -> int { return a + b }
EOF
ok "basic/proc-group" <<'EOF'
package main
foo :: proc { foo_int, foo_str }
EOF
ok "basic/only-package" <<'EOF'
package main
EOF
ok "basic/explicit-semicolons" <<'EOF'
package main
main :: proc() { a := 1; b := 2; a = b; }
x :: 1;
EOF
ok "basic/no-final-newline" <<'EOF'
package main
x: int
EOF

############################ ВЫРАЖЕНИЯ ############################
ok "expr/arith-logic" <<'EOF'
package main
main :: proc() {
	a := 1 + 2 * 3 - 4 / 2 % 3
	b := a & 1 | 2 ~ 3 &~ 4
	c := a << 2 >> 1
	d := a < 1 && a > 0 || a == 2 && a != 3
	e := a <= 1 && a >= 2
	f := -a + +a
	g := !d
	h := ~a
}
EOF
ok "expr/postfix" <<'EOF'
package main
main :: proc() {
	a := p^
	b := arr[0]
	c := s.field
	d := f(1, 2, 3)
	e := a.b.c(1)[2]^
	g := &x
	h := f()
}
EOF
ok "expr/ternary-orelse-range" <<'EOF'
package main
main :: proc() {
	a := c ? 1 : 2
	b := 1 if c else 2
	d := 1 when c else 2
	e := f() or_else 0
	g := f() or_return
	h := f() or_break
	i := f() or_continue
}
EOF
ok "expr/cast-autocast" <<'EOF'
package main
main :: proc() {
	a := cast(int) x
	b := cast(^int) p
	c := auto_cast y
}
EOF
ok "expr/assign-ops" <<'EOF'
package main
main :: proc() {
	a += 1
	a -= 1
	a *= 2
	a /= 2
	a %= 3
	a %%= 3
	a |= 1
	a ~= 1
	a &= 1
	a &~= 1
	a <<= 1
	a >>= 1
	a &&= b
	a ||= b
	x, y = y, x
}
EOF

############################ ЛЕКСЕР ############################
ok "lex/numbers" <<'EOF'
package main
a :: 0xFF
b :: 0b1010
c :: 0o17
d :: 1_000_000
e :: 1.5e3
f :: 2.0
g :: 3i
EOF
ok "lex/strings-runes" <<'EOF'
package main
a :: "hello\n\t\"q\""
b :: `raw \n string`
c :: 'x'
d :: '\n'
e :: "\x41\u00e9\101"
EOF
ok "lex/comments" <<'EOF'
package main
// строчный
/* блочный /* вложенный */ ещё */
x :: 1 // хвост
EOF
ok "lex/newline-semicolons" <<'EOF'
package main
main :: proc() {
	a := 1
	b := 2
	if a < b {
		a = b
	}
	return
}
EOF
bad "lex/unclosed-string" <<'EOF'
package main
x :: "abc
EOF
bad "lex/unclosed-comment" <<'EOF'
package main
/* abc
x :: 1
EOF

############################ ОПЕРАТОРЫ ############################
ok "stmt/if-else" <<'EOF'
package main
main :: proc() {
	if a {
	} else if b {
	} else {
	}
	if x := f(); x > 0 {
	}
}
EOF
ok "stmt/for-variants" <<'EOF'
package main
main :: proc() {
	for {
		break
	}
	for a < 10 {
		a += 1
	}
	for i in 0..<10 {
	}
	for i in 0..=10 {
	}
	for k, v in m {
	}
	for i := 0; i < 10; i += 1 {
	}
	for i in a do f(i)
}
EOF
ok "stmt/switch" <<'EOF'
package main
main :: proc() {
	switch x {
	case 1:
		a := 1
	case 2, 3:
		b := 2
	case:
		c := 3
	}
	switch y := f(); y {
	case 1:
	}
}
EOF
ok "stmt/fallthrough" <<'EOF'
package main
main :: proc() {
	switch x {
	case 1:
		fallthrough
	case 2:
		a := 1
		fallthrough
	case 3:
	}
}
EOF
ok "stmt/when" <<'EOF'
package main
main :: proc() {
	when X {
		a := 1
	} else when Y {
		a := 2
	} else {
		a := 3
	}
}
EOF
ok "stmt/defer-using-return" <<'EOF'
package main
main :: proc() {
	defer free(p)
	using fmt
	return
}
EOF
ok "stmt/labels-break-continue" <<'EOF'
package main
main :: proc() {
	outer: for {
		for {
			continue outer
		}
		break outer
	}
}
EOF
ok "stmt/nested-block" <<'EOF'
package main
main :: proc() {
	{
		a := 1
	}
}
EOF

############################ ТИПЫ ############################
ok "type/struct-enum-basic" <<'EOF'
package main
Point :: struct {
	x: int,
	y: f32,
}
Color :: enum {
	Red,
	Green = 2,
	Blue,
}
Id :: distinct int
EOF
ok "type/composite" <<'EOF'
package main
p: ^int
s: []int
a: [10]int
d: [dynamic]int
m: map[string]int
f: proc(a: int) -> int
b: bit_set[Flag]
EOF
ok "type/builtin" <<'EOF'
package main
a: bool
b: int
c: i8
d: u64
e: f32
g: string
h: rune
i: rawptr
j: byte
EOF

############################ ДИРЕКТИВЫ ############################
ok "dir/file-tags" <<'EOF'
#+build windows, linux
#+private
package main
x :: 1
EOF
ok "dir/struct-directives" <<'EOF'
package main
A :: struct #packed { a: int }
B :: struct #raw_union { a: int, b: f32 }
C :: struct #align(16) { a: int }
D :: struct #packed #align(4) { a: int }
EOF
ok "dir/stmt-directives" <<'EOF'
package main
main :: proc() {
	#partial switch x {
	case A:
	}
	#no_bounds_check a[0] = 1
}
EOF

############################ ИСПРАВЛЕНИЯ ИЗ СПИСКА (пункты 1–15) ############################
ok "fix2/local-struct" <<'EOF'
package main
main :: proc() {
	P :: struct { x: int }
}
EOF
ok "fix2/local-enum-distinct" <<'EOF'
package main
main :: proc() {
	E :: enum { A, B }
	MyInt :: distinct int
}
EOF
ok "fix2/local-proc" <<'EOF'
package main
main :: proc() {
	helper :: proc(a: int) -> int { return a }
}
EOF
ok "fix2/local-proc-group" <<'EOF'
package main
main :: proc() {
	foo :: proc { foo_int, foo_str }
}
EOF
ok "fix2/local-type-forms" <<'EOF'
package main
main :: proc() {
	Arr :: [4]int
	Ptr :: ^int
	Sl :: []int
	M :: map[string]int
	B :: bit_set[E]
	Fn :: proc(a: int) -> int
	Fn2 :: proc()
}
EOF
ok "fix2/local-multi-names" <<'EOF'
package main
main :: proc() {
	A, B :: 1, 2
	C :: 3
}
EOF
ok "fix2/local-in-nested-places" <<'EOF'
package main
main :: proc() {
	if a {
		P :: struct { x: int }
	}
	for {
		E :: enum { A }
		break
	}
	switch x {
	case 1:
		T :: distinct int
	}
	when X {
		H :: proc() { }
	}
}
EOF
ok "fix2/local-proc-before-use" <<'EOF'
package main
main :: proc() {
	helper :: proc(a: int) -> int { return a }
	b := helper(1)
}
EOF
bad "bad/local-decl-missing-rhs" <<'EOF'
package main
main :: proc() {
	T ::
}
EOF
bad "bad/local-struct-unclosed" <<'EOF'
package main
main :: proc() {
	P :: struct { x: int
}
EOF
ok "fix3/import-alias" <<'EOF'
package main
import fmt "core:fmt"
import "core:os"
EOF
ok "fix4/import-after-decl" <<'EOF'
package main
x :: 1
import "core:fmt"
EOF
ok "fix4/top-level-when" <<'EOF'
package main
when X {
	A :: 1
} else {
	A :: 2
}
EOF
ok "fix1/multi-const" <<'EOF'
package main
A, B :: 10, 20
EOF
ok "fix7/multipointer" <<'EOF'
package main
p: [^]int
EOF
ok "fix8/infer-array" <<'EOF'
package main
a: [?]int
EOF
ok "fix9/fixed-cap-dynamic" <<'EOF'
package main
a: [dynamic; 10]int
EOF
ok "fix10/bit_set-variants" <<'EOF'
package main
a: bit_set[E; u8]
b: bit_set[0..<8]
c: bit_set[E]
EOF
ok "fix11/union-types" <<'EOF'
package main
U :: union { int, string, bool }
V :: union #no_nil { int, f32 }
EOF
ok "fix12/struct-using-tag" <<'EOF'
package main
S :: struct {
	using p: P,
	x: int "json:x",
}
EOF
ok "fix13/enum-base" <<'EOF'
package main
E :: enum u32 { A, B }
F :: enum u8 { X = 1 }
EOF
ok "fix14/qualified-types" <<'EOF'
package main
v: math.Vec2
f :: proc(c: rl.Color) -> strings.Builder {
}
EOF
ok "fix15/poly" <<'EOF'
package main
f :: proc(x: $T) {}
g :: proc($T: typeid) {}
h :: proc(t: typeid) {}
EOF

############################ НЕВЕРНЫЕ ПРОГРАММЫ (должны падать) ############################
bad "bad/no-package" <<'EOF'
main :: proc() {}
EOF
bad "bad/import-before-package" <<'EOF'
import "core:fmt"
package main
EOF
bad "bad/unbalanced-brace" <<'EOF'
package main
main :: proc() {
EOF
bad "bad/if-without-block" <<'EOF'
package main
main :: proc() {
	if a
}
EOF
bad "bad/else-on-next-line" <<'EOF'
package main
main :: proc() {
	if a {
	}
	else {
	}
}
EOF
bad "bad/incomplete-expr" <<'EOF'
package main
x := 
EOF
bad "bad/stray-paren" <<'EOF'
package main
x :: 1)
EOF
bad "bad/missing-proc-body" <<'EOF'
package main
main :: proc(
EOF
bad "bad/double-operator" <<'EOF'
package main
x :: 1 + * 2
EOF
bad "bad/struct-missing-type" <<'EOF'
package main
S :: struct { a: }
EOF

############################ ПОКА НЕ ПОДДЕРЖИВАЕТСЯ (todo) ############################
todo "todo/implicit-selector" <<'EOF'
package main
main :: proc() { x := .A }
EOF
todo "todo/when-odin-os" <<'EOF'
package main
when ODIN_OS == .Windows {
	A :: 1
}
EOF
todo "todo/proc-literal" <<'EOF'
package main
main :: proc() { f := proc() {} }
EOF
todo "todo/compound-literal" <<'EOF'
package main
main :: proc() { p := Point{1, 2} }
EOF
todo "todo/array-literal" <<'EOF'
package main
a := [3]int{1, 2, 3}
EOF
todo "todo/type-switch" <<'EOF'
package main
main :: proc() { switch v in x { case int: } }
EOF
todo "todo/bit_field" <<'EOF'
package main
F :: bit_field u32 { a: u8 | 3 }
EOF
todo "todo/named-returns" <<'EOF'
package main
f :: proc() -> (a: int, b: int) { return }
EOF
todo "todo/proc-type-unnamed-params" <<'EOF'
package main
f: proc(int) -> int
EOF
todo "todo/default-param" <<'EOF'
package main
f :: proc(a: int = 1) {}
EOF
todo "todo/attribute-parens" <<'EOF'
package main
@(private)
foo :: proc() {}
EOF
todo "todo/size_of-type" <<'EOF'
package main
main :: proc() { n := size_of(int) }
EOF
todo "todo/empty-stmt" <<'EOF'
package main
main :: proc() { a := 1;; b := 2 }
EOF
todo "todo/assert-directive" <<'EOF'
package main
#assert(1 == 1)
EOF

############################ ИТОГ ############################
total=$((pass+fail))
echo "================================================"
echo " ok/bad:  пройдено $pass из $total,  провалено $fail"
echo " todo:    ещё не поддержано $todo_fail,  уже работает $todo_pass"
echo "================================================"
if (( fail > 0 )); then echo "ПРОВАЛЕНЫ:"; printf '  %s\n' "${FAILED[@]}"; fi
if (( todo_pass > 0 )); then echo "Из todo уже работают (перенесите в ok):"; printf '  %s\n' "${NOWOK[@]}"; fi
(( fail == 0 ))