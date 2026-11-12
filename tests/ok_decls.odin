
package main

// ---------- структуры ----------
Vec :: struct {
    x, y, z: f32,
}

Node :: struct {
    value: int,
    grid: [3][4]int,
    dyn: [dynamic]string,
}

Mixed :: struct {
    a: int,
    b: int,
}

// ---------- перечисления ----------
Dir :: enum {
    North,
    East,
    South,
    West,
}

Level :: enum {
    Low = 1,
    Mid = 5,
    High,
}

// ---------- псевдонимы типов ----------
Speed :: f32
Handle :: int
Alias :: Speed

// ---------- константы ----------
LIMIT: int : 5
X, Y: f32 : 1.0, 2.0
A, B :: 10, 20


// ---------- переменные ----------
origin: Vec
a, b := 1, 2
names: [dynamic]string
