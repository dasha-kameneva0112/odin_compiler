package main

noop :: proc() {}
sum :: proc(a: int, b: int) -> int { return a }
Pair :: struct { x: int, y: int }

main :: proc() {
    a, b: int
    cond: bool
    arr: [4]int
    s: Pair
    a = 1 /* c */
    b = 2
}
