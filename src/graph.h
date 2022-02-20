#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_


// Пуш чара
void push(struct token item);
// Поп чара
struct token pop();
// Пуш числа
void push_int(double item);
// Поп числа
double pop_int();
// Функция конвертирования в польскую нотацию
void convert(const struct token tok[], struct token postfix_tok[], int n);
// Проверка на то, является ли чар оператором
int isOperator(char symbol);
// Проверка операнда и выставление приоритета в возврате
int prioritise(struct token tok);

// Расчет функции
double evaluate(struct token *postfix, int n, double x);


#endif  // SRC_GRAPH_H_
