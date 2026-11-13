package main

sum :: proc(a, b: int) -> int {
    return a + b
}

main :: proc() {
    x := sum \
        (10, 20)

    _ = x
}