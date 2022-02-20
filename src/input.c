#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "input.h"


int symbol_read(struct token* t) {
    char c;
    int ex_code = 1;

//  Удаляем пробелы
    do {
        c = getchar();
    } while (c == ' ');
// Проверка на число
    if (checkdigit(c) == 1) {
        t->type = TOK_NUM;
        t->value = 0;
// Пока в строке числа наращиваем в 10 раз и прибавляем
        do {
            t->value = t->value * 10 + (c - '0');
            c = getchar();
        } while (checkdigit(c) == 1);
// Возвращаем в строку не число
        ungetc(c, stdin);
    } else if ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')) {
        t->type = TOK_OPERATOR;
        t->operand = c;
    } else if ((c == '(') || (c == ')')) {
        t->type = TOK_BRACE;
        t->operand = c;
    } else if (c == 'x') {
        t->type = TOK_VAR;
        t->value = c;
    } else if (c == '\n') {
        ex_code = 0;
    } else {
        printf("n/a");
        ex_code = 2;
    }

    return ex_code;
}

// Проверка - является ли символ числом
int checkdigit(char c) {
    int ex_code = 0;

    if (c > 47 && c < 58) {
        ex_code = 1;
    }

    return ex_code;
}
