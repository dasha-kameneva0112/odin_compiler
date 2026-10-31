package main

add :: proc(
    a: int,
    b: int,
) -> int {
    return a + b
}

main :: proc() {
    x := add(
        1,
        2,
    )
}
