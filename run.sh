#!/bin/bash
set -e

FLEX_BIN="./tools/flex.exe"
BISON_BIN="./tools/win_bison.exe"
GCC_BIN="/c/msys64/ucrt64/bin/gcc.exe"

# 1. Парсер и заголовок
"$BISON_BIN" -Wall -d -o parser.tab.c parser.y

# 2. Лексер
"$FLEX_BIN" -o lex.yy.c lexer.l

# 3. Сборка
"$GCC_BIN" parser.tab.c lex.yy.c -o lexer.exe
echo "Сборка завершена."

# 4. Тесты (падение тестов не прерывает скрипт)
bash tests/run_tests.sh ./lexer.exe || true

# 5. Свой файл test.odin, если он есть (stdout и stderr в один файл)
if [ -f test.odin ]; then
    ./lexer.exe test.odin > result.txt 2>&1 || true
    echo "Результат test.odin сохранён в result.txt"
    notepad result.txt
fi