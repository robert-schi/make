#include <stdio.h>

#include "addition.h"
#include "controlBoard.h"

int main(void)
{
	if (setState(1) == 1)
	{
		return 1;
	}

    int a, b;
    printf ("Insert two numbers: ");
    if(scanf("%d %d", &a, &b)!=2)
    {
        fputs("Invalid input\n", stderr);
        return 1;
    }
    printf("%d + %d = %d\n", a, b, Sum(a, b));

    if (setState(0) == 1)
    {
    	return 1;
    }

    return 0;
}
