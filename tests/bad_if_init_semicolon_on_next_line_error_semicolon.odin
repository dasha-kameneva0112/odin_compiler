package main

noop :: proc() {}

main :: proc() {
    if x := 10
        ; x > 0 {
        noop()
    }
}