package main;

import "core:fmt";

x := 1; y := 2;

main :: proc() {
    a := 1; b := 2
    c := 3;
    { d := 4; };
    if a > 0 { b = 1; } else { b = 2; }
}
