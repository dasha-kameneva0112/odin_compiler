package main

Pair :: struct {
    x: int,
    y: int,
}

main :: proc() {
    p := Pair{
        x = 10,
        y = 20,
    }
    _ = p.x
}