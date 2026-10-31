package main

ops :: proc() {
    a := 1
    b := 2
    c := a + b - a * b / a % b
    d := a %% b
    e := a & b | a ~ b
    f := a &~ b
    g := a << 1 >> 2
    h := -a + +b
    i := ~a
    j := !true
    k := a < b
    l := a > b
    m := a <= b
    n := a >= b
    o := a == b
    p := a != b
    q := a < b && b > a || a == b
    r := a..b
    s := a..<b
    t := a..=b
    u := &a
    v := u^
    a += 1
    a -= 1
    a *= 2
    a /= 2
    a %= 3
    a %%= 3
    a |= 1
    a ~= 1
    a &= 1
    a &~= 1
    a <<= 1
    a >>= 1
    flag := true
    flag &&= false
    flag ||= true
}
