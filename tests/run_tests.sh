#!/bin/bash
# Использование: bash tests/run_tests.sh [путь_к_компилятору]
# ok_*.odin  -> должны разобраться (в выводе "Good")
# bad_*.odin -> парсер должен сам сообщить об ошибке

BIN=${1:-./lexer.exe}
DIR=$(dirname "$0")

if [ ! -x "$BIN" ]; then
    echo "Компилятор не найден: $BIN"
    exit 2
fi

pass=0; fail=0

for f in "$DIR"/ok_*.odin; do
    out=$("$BIN" "$f" 2>&1)
    if echo "$out" | grep -q "^Good"; then
        echo "[ OK ] $(basename "$f")"; pass=$((pass+1))
    else
        echo "[FAIL] $(basename "$f")  (ожидалось Good)"
        echo "$out" | head -3 | sed 's/^/        /'
        fail=$((fail+1))
    fi
done

for f in "$DIR"/bad_*.odin; do
    out=$("$BIN" "$f" 2>&1)
    if echo "$out" | grep -qE "Syntax error|Lex error"; then
        echo "[ OK ] $(basename "$f")  (парсер отверг файл, как и ожидалось)"; pass=$((pass+1))
    else
        echo "[FAIL] $(basename "$f")  (парсер принял файл с ошибкой, а должен был отвергнуть)"
        echo "$out" | head -3 | sed 's/^/        /'
        fail=$((fail+1))
    fi
done

echo "-----"
echo "Пройдено: $pass, провалено: $fail"
[ $fail -eq 0 ]