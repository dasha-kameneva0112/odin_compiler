package main

import "core:fmt"

// Простая процедура.
greet :: proc(name: string) {
    fmt.println("Привет,", name)
}

// Процедура, принимающая процедуру в качестве аргумента.
// Тип параметра `callback` — `proc(string)`.
do_greeting :: proc(callback: proc(name: string), name: string) {
    callback(name)
}

main :: proc() {
    // Переменная `my_greeter` имеет процедурный тип `proc(string)`.
    my_greeter: proc(name: string) = greet
    my_greeter("Мир") // Привет, Мир

    // Передача процедуры в другую процедуру.
    do_greeting(greet, "Odin") // Привет, Odin
}