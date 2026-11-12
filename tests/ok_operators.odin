
package main

ops :: proc() {
    a := 1
    b := 2

    // Арифметика
    c := a + b - a * b / a % b
    d := a %% b

    // Унарные операторы
    e := -a + +b
    f := !true

    // Сравнения
    g := a < b
    h := a > b
    i := a <= b
    j := a >= b
    k := a == b
    l := a != b

    // Логические операторы
    m := a < b && b > a || a == b

    // Диапазоны
    n := a..b
    o := a..<b
    p := a..=b

    // Арифметические присваивания
    a += 1
    a -= 1
    a *= 2
    a /= 2
    a %= 3
    a %%= 3

    // Логические присваивания
    flag := true
    flag &&= false
    flag ||= true
}
