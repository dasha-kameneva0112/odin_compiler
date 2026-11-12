package main

noop :: proc() {}

main :: proc() {
    x := 1

    switch x {
    case 0:
        noop()

    case 1:
        noop()

    case:
        noop()
    }
}