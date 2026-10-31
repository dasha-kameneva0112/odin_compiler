package main

// Переводы строк внутри () и [] не должны превращаться в ';'

func1 :: proc(
    a: int,
    b: int
) -> int {
    return a +
        b
}

func2 :: proc(p
: int) {
}

func3 :: proc(a: int,
              b: int) {
}

calc :: proc() {
    x := (1 + (2 * 3)
        + 4)
    y := func1(
        1,
        2
    )
    z := func1(1,
        2)
    arr: [
        4
    ]int
    w := func1(func1(1, 2
    ), 3)
    q := arr[
        0
    ]
}

nested :: proc() {
    r := func1(
        1,
        func1(
            2,
            3
        )
    )
    // после скобок обычные операторы по-прежнему разделяются
    a := 1
    b := 2
}

main :: proc() {
}
