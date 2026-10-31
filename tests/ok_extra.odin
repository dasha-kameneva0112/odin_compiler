package main

// Дорогие/спорные конструкции. Если этот файл падает, а ok_core проходит,
// значит проблема именно в этих правилах.

import "core:fmt"

@private
hidden :: proc() {
}

@(link_name="foo")
exported :: proc() {
}

foo_int :: proc(a: int) -> int {
    return a
}

foo_str :: proc(a: string) -> string {
    return a
}

foo :: proc { foo_int, foo_str }

Shape :: union {
    a: int,
    b: f32,
}

Perms :: bit_set[Color]

Mat :: matrix[2, 2]f32

Color :: enum {
    Read,
    Write,
}

containers :: proc() {
    d: [dynamic]int
    m: map[string]int
    pr: proc(a: int) -> int
    ppp: ^^int
}

when_test :: proc() {
    when true {
        x := 1
    } else {
        x := 2
    }
}

ternary_test :: proc(a: int) {
    b := a > 0 ? 1 : 2
    c := 1 if a > 0 else 2
}

or_test :: proc() {
    a := foo_int(1) or_else 0
}

using_test :: proc() {
    using fmt
}
