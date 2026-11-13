package main

noop :: proc() {}
sum :: proc(a: int, b: int) -> int { return a }
Pair :: struct { x: int, y: int }

Ta :: proc() -> (int, int) {
 return 1,
 2
}
