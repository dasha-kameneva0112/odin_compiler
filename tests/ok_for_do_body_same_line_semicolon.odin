package main

noop :: proc() {}

main :: proc() {
    for true do noop()
}