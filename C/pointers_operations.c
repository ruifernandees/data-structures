#include <stdio.h>

int main()
{
    int i, *q;
    i = 10;
    q = &i;

    printf("Início - q: %p\n", q);
    
    q++;

    printf("Final - q: %p\n", q);

    return 0;
}