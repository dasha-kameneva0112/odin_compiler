package main

import "core:fmt"

main :: proc() {
    x := 1
    condition := true
    switch x {
    case 1:
        if condition {
            fallthrough // ❌ Ошибка: fallthrough должен быть последним оператором в case
        }
        fmt.println("Не выполнится, если сработал if")
    case 2:
        // ...
    }
}