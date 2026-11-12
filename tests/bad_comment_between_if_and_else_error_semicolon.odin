package main

noop :: proc() {}

main :: proc() {
    if true {
        noop()
    }
    // comment
    else {
        noop()
    }
}