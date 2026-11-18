package main

import "core:fmt"

f :: proc() -> (int, int,) {
  return 10, 20
}

main :: proc() {
    a, b := f()

    fmt.println("Hello, World!")
    fmt.println(a, b)
}