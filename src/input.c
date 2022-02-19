#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_function() {
//    char ch, Newch;
    char* str = malloc(10 * sizeof(char));
       printf("\n Уравнение:  ");
        scanf("%s", str);
        getchar();
       
//       printf("\n Search for :  ");
//       scanf("%c", &ch);
//       getchar();
//
//       printf("\n New Character :  ");
//       scanf("%c", &Newch);
    return str;
}

char* replace_x(char* str, int a) {
    char* str_new = malloc(10 * sizeof(char));
    strcpy(str_new, str);
    char b = a + '0';
    printf("\nTEST %d\n", a);
    for(unsigned long i = 0; i <= strlen(str); i++) {
        if(str_new[i] == 'x') {
            str_new[i] = b;
        }
    }
    printf("\n Уравнение с заменой = %s \n",  str_new);
    return str_new;
}
