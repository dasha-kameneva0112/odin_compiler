package main

noop :: proc() {}

main :: proc() {
    switch x := 10; x {
    case 10:
        noop()
    case:
        noop()
    }
}