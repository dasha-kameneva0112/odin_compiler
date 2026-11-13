package main

noop :: proc() {}
sum :: proc(a: int, b: int) -> int { return a }
Pair :: struct { x: int, y: int }
tryit :: proc() -> (int, bool) { return 0, true }

Ta :: proc() -> bool {
 v := tryit() or_return
 _ = v
 return true
}
