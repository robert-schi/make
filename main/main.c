#include <stdio.h>

#include "functions.h"

int main(void)
{
    int a, b;
    printf("Insert two numbers: ");
    if(scanf("%d %d", &a, &b)!=2)
    {
        fputs("Invalid input\n", stderr);
        return 1;
    }
    printf("%d + %d = %d\n", a, b, Sum(a, b));
    return 0;
}