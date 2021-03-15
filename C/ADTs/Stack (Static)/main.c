#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    tStack *p;

    p = createStack();

    for (int i = 0; i < 10; i++)
    {
        push(p, (element) i);
    }

    int x;

    while(!isEmpty(p))
    {
        pop(p, &x);
        printf("%d ", x);
    }
    printf("\n");


    return 0;
}