package main

sum :: proc(a, b: int) -> int {
    return a + b
}

main :: proc() {
    x := sum(1, sum(2, 3
    )
    )
    _ = x
}
