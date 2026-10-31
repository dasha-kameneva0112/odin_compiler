#+build windows, linux
#+private file
package main

main :: proc() {
    x := 1
    #partial switch x {
    case 1:
        x = 2
    }
}
