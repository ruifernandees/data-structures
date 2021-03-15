#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct {
    int x, y;
} point;

int main()
{
    tStack *p;

    p = createStack(sizeof(point));

    point myPoint;

    for (int i = 0; i < 10; i++)
    {
        myPoint.x = i;
        myPoint.y = -i;
        push(p, &myPoint);
    }

    while (!isEmpty(p))
    {
        pop(p, &myPoint);
        printf("(%d, %d) ", myPoint.x, myPoint.y);
    }
    printf("\n");

    destroy(p);

    return 0;
}