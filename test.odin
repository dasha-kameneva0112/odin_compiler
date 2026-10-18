package main

import "core:fmt"

MyStruct :: struct {
value: int
}

main :: proc() {
    // Строковые литералы
    name := "Hello, Odin!"
    message := "Hello\nWorld"
    raw := `hello world`

    // Числовые литералы
    a := 200
    b := 2.5
    c := 2e4
    d := 123i

    // Символьные литералы
    letter := 'A'
    newline := '\n'

    // Булевы значения
    bool_name := true

    // Переменные и вызовы функций
    x := 1
    y := 2

    fmt.println("Hello, Odin!")
    fmt.println(name)
    fmt.println(x, y)

    switch x {
    case 1:
        f()
        fallthrough
    case 2:
        fallthrough
    case 3:
        g()
    case:
        h()
    }

}
