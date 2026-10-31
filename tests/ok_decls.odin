package main

import "core:fmt"
import "core:os"
import "core:strings"

Vec :: struct { x, y, z: f32 }

Node :: struct {
    value: int,
    next:  ^Node,
    kids:  []^Node,
    grid:  [3][4]int,
    dyn:   [dynamic]string,
    table: map[string][]int,
    cb:    proc(a: int) -> bool,
}

Mixed :: struct {
    a: int,
    b: int
}

Dir :: enum { North, East, South, West }

Level :: enum {
    Low = 1,
    Mid = 5,
    High
}

Speed :: distinct f32
Handle :: distinct rawptr
Alias :: Speed

LIMIT: int : 5
X, Y: f32 : 1.0, 2.0
origin: Vec
a, b := 1, 2
names: [dynamic]string
