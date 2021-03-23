#include <stdio.h>
#include "queue.h"


int main()
{
    queue *q;
    q = createQueue();

    for (int i = 0; i < 10; i++)
    {
        insert(q, i);
    }

    elem x;

    removeElement(q, &x); // Remove 0
    removeElement(q, &x); // Remove 1

    insert(q, 11);

    while (!isEmpty(q))
    {
        removeElement(q, &x);
        printf("%d ", x);
    }
    printf("\n");


    return 0;
}