
package main

strs :: proc() {
    // Обычные строки
    a := "hello"
    b := ""
    c := "line1\nline2"
    d := "tab\there"
    e := "quote \" inside"
    f := "back\\slash"

    // Escape-последовательности
    g := "\x41\x42"
    h := "caf\u00e9"
    i := "smile \U0001F600"
    p := "octal \101"

    // Содержимое, похожее на синтаксис
    j := "http://example.com"
    k := "/* не комментарий */"
    o := "a;b"
    q := "paren ( внутри строки"

    // Unicode
    l := "Привет, мир"

    // Raw-строки
    m := `raw \n string`
    n := `multi
line raw`
}

after_string :: proc() {
}
