#include <stdio.h>
#include <stdlib.h>

int main() {
    int cont = 0, a, array[10];
    char* string;
    printf("Insert a number: ");
    scanf("%s", string);

    while (string[cont] != 0) {
        printf("%d\t", string[cont] - 48);
        array[cont] = string[cont] - 48;
        cont++;
    }
    for (int i = 0; i < 3; i++) {
        printf("bruh\n");
    }
}