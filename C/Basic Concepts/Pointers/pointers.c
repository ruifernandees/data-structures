#include <stdio.h>

int main()
{
    int i, *p;
    i = 10;
    p = &i;

    *p = 11;
    (*p)++;

    // printf("%d bytes\n", sizeof(i));
    printf("i = %d\n", i);

    return 0;
}