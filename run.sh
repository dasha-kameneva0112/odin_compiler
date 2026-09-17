#!/bin/bash

FLEX_BIN="./tools/flex.exe"
GPP_BIN="/c/mingw64/bin/g++.exe" 

"$FLEX_BIN" -o lexer.cpp lexer.l
"$GPP_BIN" lexer.cpp -o my_scanner.exe

./my_scanner.exe > result.txt

echo "Готово! Все лексемы сохранены в файл result.txt"
start notepad result.txt