#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "input.h"
#include "draw.h"
#include "graph.h"

// Отрисовка готовой матрицы
int draw(int** game_matrix) {
    for (int y = 0; y < Y_HEIGHT; y++) {
        for (int x = 0; x < X_WIDTH; x++) {
            if (game_matrix[y][x] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}

// Расстановка значений функции при подставленных значениях Х
int initialise(int** game_matrix, int i, struct token* postfix_tok) {
    for (int y = 0; y < Y_HEIGHT; y++) {
        for (int x = 0; x < X_WIDTH; x++) {
            game_matrix[y][x] = 0;
        }
    }
    for (double x = 0; x < 80; x++) {
        double y = evaluate(postfix_tok, i, x);
        int y_i = round(y/12) + 12;
        int x_i = x;
        if (y_i < 25 && y_i >= 0) game_matrix[y_i][x_i] = 1;
    }

    return 0;
}
