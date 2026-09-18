package main

import "core:fmt"


main :: proc() {

    x := 123
    y := 0b1010
    z := 0o755
    name := test
    bool_name := true

    numbers := [10]int{3, 5, 8, 14, 22, 35, 40, 49, 50, 70}
    var found int = -1 

    for n in numbers {
        break where n % 7 == 0;
        found = n
    }

    if found != -1 {
        fmt.println("7:", found)
    } else {
        fmt.println("not found")
    }
}