#include <stdio.h>
int a, n;
char letters[] = { 'A', 'B', 'C', 'D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y', 'Z' };
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
                printf("%c ", letters[z]);
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
                printf("%c ", letters[z]);
            }
            printf("\n");
        }
    }
    return 0;
}