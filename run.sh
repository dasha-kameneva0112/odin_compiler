#!/bin/bash

FLEX_BIN="./tools/flex.exe"
GCC_BIN="/c/msys64/ucrt64/bin/gcc.exe"

"$FLEX_BIN" -o lex.yy.c lexer.l

"$GCC_BIN" lex.yy.c -o lexer.exe

./lexer.exe test.odin > result.txt

echo "Готово! Все лексемы сохранены в файл result.txt"

start notepad result.txt