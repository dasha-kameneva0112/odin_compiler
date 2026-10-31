package main

import "core:fmt"

// ---------- константы ----------
MAX   :: 100
NAME  :: "hello"
PI: f64 : 3.14159
A, B: int : 1, 2

// ---------- глобальные переменные ----------
counter: int = 0
total := 10
x1, y1 := 1, 2
flag: bool

// ---------- типы ----------
Meters :: distinct f32
MyInt  :: int

Point :: struct {
    x: int,
    y: int,
}

Person :: struct {
    name: string,
    age:  int,
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

ptr_test :: proc(p: ^int, q: rawptr) {
    p^ = 5
    v := p^
}

types_test :: proc() {
    a: bool = true
    b: int = 1
    c: uint = 2
    d: i8 = 3
    e: i16 = 4
    f: i32 = 5
    g: i64 = 6
    h: u8 = 7
    i: u16 = 8
    j: u32 = 9
    k: u64 = 10
    l: f32 = 1.5
    m: f64 = 2.5
    n: string = "text"
    o: rune = 'a'
    p: byte = 65
    q: rawptr = nil
    r: uintptr = 0
    s: cstring = "c string"
    t: complex64 = 1.0
    u: complex128 = 2.0
    v := 3.5i
    w: b8 = true
    z: b32 = false
}

expr_test :: proc() {
    a := 1
    b := 2
    c := a + b * 3 - 4 / 2
    d := a % b
    e := (a + b) * c
    f := -a
    g := ~a
    h := !flag
    i := a & b
    j := a | b
    k := a << 2
    l := b >> 1
    m := a &~ b
    n := a < b
    o := a >= b
    p := a == b && a != c || d > e
    q := &a
    r := cast(i64) a
    s := add(1, 2)
    t := add(add(1, 2), 3)
    u := nothing
}

assign_test :: proc() {
    a := 10
    a = 20
    a += 1
    a -= 1
    a *= 2
    a /= 2
    a %= 3
    a |= 1
    a &= 7
    a <<= 1
    a >>= 1
    a: int
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

label_test :: proc() {
    outer: for i := 0; i < 3; i += 1 {
        for j := 0; j < 3; j += 1 {
            if j == 1 {
                continue outer
            }
            if i == 2 {
                break outer
            }
        }
    }
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
    pp: ^int
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
    fmt.println(r)
}
