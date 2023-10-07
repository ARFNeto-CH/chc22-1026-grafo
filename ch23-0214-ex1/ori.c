#include    <stdio.h>
#include    <iso646.h> 

int inv()
{
    static int flag = 0;
    return flag = not flag;
}

int main(int argc, char * argv[])
{
    printf("Tecle ENTER para prosseguir...");
    fgetc(stdin);
    for (int i = 0; i < 10; i++) printf("%d ", inv());
    return 0;
}