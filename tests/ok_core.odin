
package main

// ---------- константы ----------
MAX :: 100
NAME :: "hello"
PI: f64 : 3.14159
A, B: int : 1, 2

// ---------- глобальные переменные ----------
counter: int = 0
total := 10
x1, y1 := 1, 2
flag: bool

// ---------- типы ----------
MyInt :: int

Point :: struct {
    x: int,
    y: int,
}

Person :: struct {
    name: string,
    age: int,
    tags: [4]int,
}

Color :: enum {
    Red,
    Green = 5,
    Blue,
}

// ---------- процедуры ----------
nothing :: proc() {
}

add :: proc(a: int, b: int) -> int {
    return a + b
}

mul :: proc(a, b: int) -> int {
    return a * b
}

swap :: proc(a: int, b: int) -> (int, int) {
    return b, a
}

types_test :: proc() {
    a: bool = true
    b: int = 1
    c: f32 = 1.5
    d: f64 = 2.5
    e: string = "text"
    f: rune = 'a'
    g := 3.5i
    h := nil
}

expr_test :: proc() {
    a := 1
    b := 2
    c := a + b * 3 - 4 / 2
    d := a % b
    e := (a + b) * c
    f := -a
    g := !flag
    h := a < b
    i := a >= b
    j := a == b && a != c || d > e
    k := cast(int) a
    l := add(1, 2)
    m := add(add(1, 2), 3)
    n := a or_else b
    o := a if a > b else b
    p := a .. b
    q := a ..= b
}

assign_test :: proc() {
    a := 10
    a = 20
    a += 1
    a -= 1
    a *= 2
    a /= 2
    a %= 3

    b: int = 5
    c: int : 7

    d, e := 1, 2
    d, e = e, d
    d, e = swap(d, e)
}

if_test :: proc(x: int) {
    if x > 0 {
        counter += 1
    }

    if x > 0 {
        counter += 1
    } else {
        counter -= 1
    }

    if x > 10 {
        counter = 3
    } else if x > 5 {
        counter = 2
    } else {
        counter = 1
    }

    if y := add(x, 1); y > 0 {
        counter = y
    }
}

for_test :: proc() {
    for {
        break
    }

    i := 0
    for i < 10 {
        i += 1
    }

    for j := 0; j < 10; j += 1 {
        continue
    }

    arr: [5]int
    for v in arr {
        counter += v
    }

    for idx in 0..<10 {
        counter += idx
    }

    for idx in 0..=10 {
        counter += idx
    }

    for i < 3 do i += 1
}

switch_test :: proc(x: int) {
    switch x {
    case 1:
        counter = 1
    case 2, 3:
        counter = 2
        fallthrough
    case 4:
        counter = 4
    case:
        counter = 0
    }

    switch {
    case x > 0:
        counter = 1
    case:
        counter = 2
    }
}

defer_test :: proc() {
    defer counter = 0
    defer {
        counter += 1
    }
    return
}

array_test :: proc() {
    a: [3]int
    s: []int

    a[0] = 1
    a[1] = a[0] + 1
    n := a[2]

    b := [3]int{1, 2, 3}
}

nested_blocks :: proc() {
    {
        x := 1
        {
            y := x + 1
        }
    }
}

main :: proc() {
    r := add(1, 2)
}
