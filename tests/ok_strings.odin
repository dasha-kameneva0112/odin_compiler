package main

strs :: proc() {
    a := "hello"
    b := ""
    c := "line1\nline2"
    d := "tab\there"
    e := "quote \" inside"
    f := "back\\slash"
    g := "\x41\x42"
    h := "caf\u00e9"
    i := "smile \U0001F600"
    j := "http://example.com"
    k := "/* не комментарий */"
    l := "Привет, мир"
    m := `raw \n string`
    n := `multi
line raw`
    o := "a;b"
    p := "octal \101"
    q := "paren ( внутри строки"
}

after_string :: proc() {
}
