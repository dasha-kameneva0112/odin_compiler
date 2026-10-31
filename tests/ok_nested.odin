package main

deep :: proc(n: int) -> int {
    total := 0
    outer: for i := 0; i < n; i += 1 {
        switch i {
        case 0:
            continue outer
        case 1, 2:
            for j := 0; j < i; j += 1 {
                if j == 1 {
                    total += j
                } else if j == 2 {
                    break outer
                } else {
                    defer total = 0
                }
            }
        case:
            {
                inner := i * 2
                total += inner
            }
        }
    }
    when true {
        total += 1
    } else {
        total -= 1
    }
    return total
}
