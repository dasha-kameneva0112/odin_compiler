package main

sum :: proc(a, b: int) -> int {
    return a + b
}

main :: proc() {
    arr := [3]int{10, 20, 30}
    x := sum(
        arr[
            0
        ],
        2
    )
    _ = x
}
