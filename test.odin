package main

import "core:fmt"

main :: proc() {
    // это однострочный комментарий, должен полностью исчезнуть
    x := 1

   /* это простой
   многострочный комментарий,
   тоже должен исчезнуть целиком */
   y := 2

    x := 123
    y := 0b1010       
    z := 0o755        
    hex_val := 0x1F_FF 
    doz_val := 0z15_8 
    ex_dec := 0d100_000 

    pi := 3.14159
    i := .14159
    i1 := 1.
    pi2 := 3.14_159
    imag_num := 123i   
    name := "Odin Language" 
    name2 := nil 
    bool_name := true

    fmt.println("--- Literal Demonstration ---")
    fmt.printfln("x: %d, y: %d, z: %d, hex: %d", x, y, z, hex_val)
    fmt.printfln("Float: %f, Imaginary: %v, String: %s", pi, imag_num, name)

     if ptr == nil {
        fmt.println("nil")
     }
    uninit_val: int = ---
    type_zero := MyStruct{} 
    auto_array := [?]int{10, 20, 30, 40}

    numbers := [10]int{3, 5, 8, 14, 22, 35, 40, 49, 50, 70}
    var found int = -1 

    for n in numbers {
        break where n % 7 == 0
        found = n
    }

    if found != -1 {
        fmt.println("Found a number divisible by 7:", found)
    } else {
        fmt.println("Not found")
    }
}