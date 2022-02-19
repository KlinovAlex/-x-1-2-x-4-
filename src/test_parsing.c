#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "test_parsing.h"
#include "input.h"

// Объявление стека-массива чаров
char stack[25];
// Объявление стека-массива натуральных чисел - double не рабочий
double stack_int[25];
// Статус стека
int top = -1;
int top_int = -1;

int main() {
    char postfix[25];
    char* x_def = NULL;
    //   char infix[25] = "read_function()", postfix[25];
    char* str = read_function();
    for (int i = 0; i < 9; i++) {
        x_def = replace_x(str, i);
        convert(x_def, postfix);
        printf("Postfix: %s\n" , postfix);
        printf("Calculated: %lf\n" , evaluate(postfix));
        free(x_def);
    }
   
//   printf("Infix %s\n" , infix);
    free(str);
    return 0;
}

// Функция пуш
void push(char item) {
   stack[++top] = item;
}
// Функция поп
char pop() {
   return stack[top--];
}

// Пуш числа
void push_int(double item) {
   stack_int[++top_int] = item;
}

// Поп числа
char pop_int() {
   return stack_int[top_int--];
}

// Функция конвертирования в польскую нотацию
void convert(char infix[],char postfix[]) {
    double symbol;
    int j = 0;
   stack[++top] = '#';
    
   for(unsigned long i = 0; i < strlen(infix); i++) {
      symbol = infix[i];

// Если не оператор
      if(isOperator(symbol) == 0) {
         postfix[j] = symbol;
         j++;
// Если оператор
      } else {
         if(symbol == '(') {
            push(symbol);
         } else {
            if(symbol == ')') {
                
               while(stack[top] != '(') {
                  postfix[j] = pop();
                  j++;
               }
                    
               pop();   //pop out (.
            } else {
               if(prioritise(symbol) > prioritise(stack[top])) {
                  push(symbol);
               } else {
                    
                  while(prioritise(symbol) <= prioritise(stack[top])) {
                     postfix[j] = pop();
                     j++;
                  }
                        
                  push(symbol);
               }
            }
         }
      }
   }
    
   while(stack[top] != '#') {
      postfix[j] = pop();
      j++;
   }
    
   postfix[j]='\0';  // Закрыть массив чаров нульстрокой
}

// Проверка на то, является ли чар оператором
int isOperator(char symbol) {
    int ex_code = 0;
    
   switch(symbol) {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      case '(':
      case ')':
         ex_code = 1;
      break;
         default:
         ex_code = 0;
   }
    return ex_code;
}

// Расстановка приоритетов математических знаков
int prioritise(char symbol) {
    int ex_code = 0;

   switch(symbol) {
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

// Функция проверки числа
int checkdigit(char c) {
    if (c > 47 && c < 58) {
        return 1;
    } else {
        return 0;
    }
}

// Вычисление в постфиксе
double evaluate(char *postfix) {

    char ch;
    int i = 0;
    double operand1, operand2;

while((ch = postfix[i++]) != '\0') {
    //       printf("TEST TEST TEST %d TEST TEST TEST\n", checkdigit(ch));
    if(checkdigit(ch)) {
        push_int(ch-'0');  // Push the operand
    } else {
//Operator,pop two  operands
        operand2 = pop_int();
        operand1 = pop_int();
        switch(ch) {
            case '+':
                push_int(operand1+operand2);
                break;
            case '-':
                push_int(operand1-operand2);
                break;
            case '*':
                push_int(operand1*operand2);
                break;
            case '/':
                push_int(operand1/operand2);
                break;
            case '^':
                push_int(pow(operand2, operand1));
                 break;
        }
    }
}
   return stack_int[top_int];
}
