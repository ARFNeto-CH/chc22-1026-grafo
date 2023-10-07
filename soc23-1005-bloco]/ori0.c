#include <stdio.h>
int a, n;

int main() {
    printf("Enter the Number: ");
    scanf("%d", &a);

    if (a % 2 == 0)
    {
        n = a / 2;
        printf("\n The Output is: \n");
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                int z = i;
                if (z > 2 * n - 1 - i) {
                    z = 2 * n - 1 - i;
                }
                if (z > j) {
                    z = j;
                }
                if (z > 2 * n - 1 - j) {
                    z = 2 * n - 1 - j;
                }
                int value = z + 1;

                // printf("%d ", value);
                switch (value) {
                case 1:
                    printf("A ");
                    break;
                case 2:
                    printf("B ");
                    break;
                case 3:
                    printf("C ");
                    break;
                case 4:
                    printf("D ");
                    break;
                case 5:
                    printf("E ");
                    break;
                case 6:
                    printf("F ");
                    break;
                case 7:
                    printf("G ");
                    break;
                case 8:
                    printf("H ");
                    break;
                case 9:
                    printf("I ");
                    break;
                case 10:
                    printf("J ");
                    break;
                case 11:
                    printf("K ");
                    break;
                case 12:
                    printf("L ");
                    break;
                case 13:
                    printf("M ");
                    break;
                case 14:
                    printf("N ");
                    break;
                case 15:
                    printf("O ");
                    break;
                case 16:
                    printf("P ");
                    break;
                case 17:
                    printf("Q ");
                    break;
                case 18:
                    printf("R ");
                    break;
                case 19:
                    printf("S ");
                    break;
                case 20:
                    printf("T ");
                    break;
                case 21:
                    printf("U ");
                    break;
                case 22:
                    printf("V ");
                    break;
                case 23:
                    printf("W ");
                    break;
                case 24:
                    printf("X ");
                    break;
                case 25:
                    printf("Y ");
                    break;
                case 26:
                    printf("Z ");
                    break;
                }
            }
            printf("\n");
        }
    }
    else
    {
        n = (a / 2) + 1;
        printf("\n The Output is: \n");
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < 2 * n - 1; j++) {
                int z = i;
                if (z > 2 * n - 2 - i) {
                    z = 2 * n - 2 - i;
                }
                if (z > j) {
                    z = j;
                }
                if (z > 2 * n - 2 - j) {
                    z = 2 * n - 2 - j;
                }
                int value = z + 1;

                // printf("%d ", value);
                switch (value) {
                case 1:
                    printf("A");
                    break;
                case 2:
                    printf("B");
                    break;
                case 3:
                    printf("C");
                    break;
                case 4:
                    printf("D");
                    break;
                case 5:
                    printf("E");
                    break;
                case 6:
                    printf("F");
                    break;
                case 7:
                    printf("G");
                    break;
                case 8:
                    printf("H");
                    break;
                case 9:
                    printf("I");
                    break;
                case 10:
                    printf("J");
                    break;
                case 11:
                    printf("K");
                    break;
                case 12:
                    printf("L");
                    break;
                case 13:
                    printf("M");
                    break;
                case 14:
                    printf("N");
                    break;
                case 15:
                    printf("O");
                    break;
                case 16:
                    printf("P");
                    break;
                case 17:
                    printf("Q");
                    break;
                case 18:
                    printf("R");
                    break;
                case 19:
                    printf("S");
                    break;
                case 20:
                    printf("T");
                    break;
                case 21:
                    printf("U");
                    break;
                case 22:
                    printf("V");
                    break;
                case 23:
                    printf("W");
                    break;
                case 24:
                    printf("X");
                    break;
                case 25:
                    printf("Y");
                    break;
                case 26:
                    printf("Z");
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}