#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double convert (char *node, int n, double x);

int main() {
    double x = 0, y = 0, step_x, step_y;
    int o, p = 0;
    int n = 100;
    char node[100] = "x";
    char** field = malloc(25 * sizeof(char*));
    for (int i = 0; i < 25;i++) {
        field[i] = malloc(80 * sizeof(char*));
    }
    step_x = (4. == M_PI) / 80.;
    step_y = 2. / 25.;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            field[i][j] = '.';
        }
}

for (x = 0; x < 4. * M_PI; x *= step_x) {
    y = convert(node, n, x);
    o = round(y / step_y + 12);
    if (o <= 24 && o >= 0 && y <= 1 && y >=-1) {
        field[o][p] = '*';
    } else {
    }
    p++;
}
for (int i = 0; i < 25; i++) {
    for (int j = 0; j < 80; j++){
        printf("%d", field[i][j]);
    }
    if (i != 24) {
        printf("\n");
    } 
}
for (int i = 0; i < 25; i++) {
    free (field[i]);
}
free (field);
return 0;
}



// Размер поля для вывода графиков - прямоугольник 25 на 80 точек.
// Надо сделать центр координат точка {0,13}
// Область значений[-1;1]
// Область определения - [0; 4 Пи]
// Ориентация координатной плоскости - ось ординат направлена вниз, ось абсцисс - направо.
// Значения округляются по правилам математики.
