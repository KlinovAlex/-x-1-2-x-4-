#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "input.h"
#include "graph.h"
#include "draw.h"

// Объявление стека-массива чаров
struct token stack[25];
// Объявление стека-массива натуральных чисел - double не рабочий
double stack_int[25];
// Статус стека
int top = -1;
int top_int = -1;

int main() {
    struct token tok[25];
    struct token postfix_tok[25];
    int i = 0, ex_code2 = 0;

    // Выделение памяти из кучи для матрицы поля
    int** game_matrix = malloc(Y_HEIGHT * X_WIDTH * sizeof(int) + Y_HEIGHT * sizeof(int*));
    int* values_array = (int*) (game_matrix + Y_HEIGHT);
    for (int nm = 0; nm < Y_HEIGHT; nm++) game_matrix[nm] = values_array + X_WIDTH * nm;

    while (symbol_read(&tok[i], &ex_code2) == 1) {
        i++;
    }
    if (ex_code2 != 2) {
        convert(tok, postfix_tok, i);
        initialise(game_matrix, i, postfix_tok);
        draw(game_matrix);
    }
    free(game_matrix);

    return 0;
}

// Функция пуш
void push(struct token item) {
    stack[++top] = item;
}
// Функция поп
struct token pop() {
    return stack[top--];
}

// Пуш числа
void push_int(double item) {
    stack_int[++top_int] = item;
}

// Поп числа
double pop_int() {
    return stack_int[top_int--];
}

// Функция конвертирования в польскую нотацию
void convert(const struct token tok[], struct token postfix_tok[], int n) {
    struct token symbol;
    int j = 0;
    stack[++top].operand = '#';

    for (int i = 0; i < n; i++) {
        symbol = tok[i];

// Если не оператор
      if (symbol.type == TOK_NUM || symbol.type == TOK_VAR) {
         postfix_tok[j] = symbol;
         j++;
// Если оператор
      } else {
         if (symbol.type == TOK_BRACE && symbol.operand == '(') {
            push(symbol);
         } else {
            if (symbol.type == TOK_BRACE && symbol.operand == ')') {
               while (stack[top].type != TOK_BRACE && stack[top].operand != '(') {
                  postfix_tok[j] = pop();
                  j++;
               }
               pop();   //  Вытащить скобку "("
            } else {
               if (prioritise(symbol) > prioritise(stack[top])) {
                  push(symbol);
               } else {
                  while (prioritise(symbol) <= prioritise(stack[top])) {
                     postfix_tok[j] = pop();
                     j++;
                  }
                  push(symbol);
               }
            }
         }
      }
    }
    while (stack[top].operand != '#') {
        postfix_tok[j] = pop();
        j++;
    }
}

// Расстановка приоритетов математических знаков
int prioritise(struct token tok) {
    int ex_code = 0;

    switch (tok.operand) {
      case '+':
      case '-':
         ex_code = 2;
         break;
      case '*':
      case '/':
         ex_code = 3;
         break;
      case '^':
         ex_code = 4;
         break;
      case '(':
      case ')':
      case '#':
         ex_code = 1;
         break;
    }

    return ex_code;
}

// Вычисление в постфиксе
double evaluate(struct token *postfix_tok, int n, double x) {
    int i = 0;
    double operand1, operand2;

    while (i < n) {
        if (postfix_tok[i].type == TOK_NUM || postfix_tok[i].type == TOK_VAR) {
// Вставляем операнд
            if (postfix_tok[i].type == TOK_VAR) postfix_tok[i].value = x;
            push_int(postfix_tok[i].value);
        } else {
// Попали на оператора, берем два операнда из стека
            operand2 = pop_int();
            operand1 = pop_int();
            switch (postfix_tok[i].operand) {
                case '+':
                    push_int((double)(operand1+operand2));
                    break;
                case '-':
                    push_int(operand1-operand2);
                    break;
                case '*':
                    push_int(operand1*operand2);
                    break;
                case '/':
                    push_int((double)(operand1/operand2));
                    break;
                case '^':
                    push_int(pow(operand2, operand1));
                    break;
            }
        }
        i++;
    }

    return stack_int[top_int];
}
