package main

main :: proc() {
    a: struct { b: int, c: int } = {1, 2}
    c: [2]struct { x: int } 
}

f :: proc(p: struct { x: int }) -> struct { y: int } {
    return 1
}