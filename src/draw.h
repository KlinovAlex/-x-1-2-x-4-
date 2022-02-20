#ifndef SRC_DRAW_H_
#define SRC_DRAW_H_
#define X_WIDTH 80
#define Y_HEIGHT 25

// Отрисовка игрового поля - отправляем указатель матрицы поля
int draw(int** game_matrix);
// Инициализация игрового поля при отсутствии файла
int initialise(int** game_matrix, int i, struct token* postfix_tok);

#endif  // SRC_DRAW_H_
