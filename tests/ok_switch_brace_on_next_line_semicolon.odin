package main

noop :: proc() {}

main :: proc() {
    switch 1 

{
    case 1:
        fallthrough

    case 2:
        noop()
    }
}