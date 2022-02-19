#include <stdlib.h>
#include <stdio.h>
#define x_width 80
#define y_height 25

// Отрисовка игрового поля - отправляем указатель матрицы поля
int draw(int** game_matrix);
// Инициализация игрового поля при отсутствии файла
int initialise(int** game_matrix);






int main() {
    // Выделение памяти из кучи для матрицы поля
    int** game_matrix = malloc(y_height * x_width * sizeof(int) + y_height * sizeof(int*));
    int* values_array = (int*) (game_matrix + y_height);
    for (int i = 0; i < y_height; i++) game_matrix[i] = values_array + x_width * i;
    
    initialise(game_matrix);
    draw(game_matrix);

    free(game_matrix);
}

int draw(int** game_matrix) {
    system("clear");
    for (int y = 0; y < y_height; y++) {
        for (int x = 0; x < x_width; x++) {
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

int initialise(int** game_matrix) {

    for (int y = 0; y < y_height; y++) {
        for (int x = 0; x < x_width; x++) {
            game_matrix[y][x] = 0;
        }
    }
    return 0;
}
