package main

main :: proc() {
    arr := [3]int{10, 20, 30}

    for i in 0..<3 {
        _ = arr[i]
    }
}