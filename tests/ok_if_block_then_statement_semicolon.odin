package main

noop :: proc() {}

main :: proc() {
    if true {
        a := 10
        _ = a
    }

    noop()
}