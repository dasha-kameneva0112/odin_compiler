package main

noop :: proc() {}
sum :: proc(a: int, b: int) -> int { return a }
Pair :: struct { x: int, y: int }
tryit :: proc() -> (int, bool) { return 0, true }

main :: proc() {
    a, b: int
    cond: bool
    arr: [4]int
    s: Pair
    for {
     v := tryit() or_break
     _ = v
    }
}
