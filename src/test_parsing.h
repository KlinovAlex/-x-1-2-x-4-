#ifndef SRC_TEST_PARSING_H_
#define SRC_TEST_PARSING_H_

// Пуш чара
void push(char item);
// Поп чара
char pop();
// Пуш числа
void push_int(double item);
// Поп числа
char pop_int();
// Функция конвертирования в польскую нотацию
void convert(char infix[],char postfix[]);
// Проверка на то, является ли чар оператором
int isOperator(char symbol);
// Проверка операнда и выставление приоритета в возврате
int prioritise(char symbol);
// Функция проверки числа
int checkdigit(char c);
// Расчет функции
double evaluate(char *postfix);


#endif  // SRC_TEST_PARSING_H_
