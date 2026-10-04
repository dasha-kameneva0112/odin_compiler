#!/bin/bash
set -e

FLEX_BIN="./tools/flex.exe"
BISON_BIN="./tools/win_bison.exe"
GCC_BIN="/c/msys64/ucrt64/bin/gcc.exe"

# 1. Генерируем парсер и заголовок
"$BISON_BIN" -Wall -d -o parser.tab.c parser.y

# 2. Генерируем лексер
"$FLEX_BIN" -o lex.yy.c lexer.l

# 3. Компилируем парсер и лексер вместе
"$GCC_BIN" parser.tab.c lex.yy.c -o lexer.exe

# 4. Проверяем наличие входного файла
if [ ! -f test.odin ]; then
    echo "Ошибка: файл test.odin не найден"
    exit 1
fi

# 5. Запускаем парсер
./lexer.exe test.odin > result.txt

echo "Готово! Результат сохранён в result.txt"

# 6. Открываем результат в Блокноте
notepad result.txt

