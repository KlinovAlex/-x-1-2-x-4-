#ifndef SRC_INPUT_H_
#define SRC_INPUT_H_
#define TOK_NUM 0
#define TOK_OPERATOR 1
#define TOK_BRACE 2
#define TOK_VAR 3

struct token {
    int type;
    double value;
    int operand;
};

// Считываем посимвольно
int symbol_read(struct token* t);
// Функция проверки числа
int checkdigit(char c);

#endif  // SRC_INPUT_H_
