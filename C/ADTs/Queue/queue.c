#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "queue.h"

struct s_queue {
    int begin, end, size;
    elem items[QueueSize];
};

queue *createQueue()
{
    queue *q;
    q = (queue *) malloc(sizeof(queue));

    assert(q != NULL);

    q->size = 0;
    q->begin = 0;
    q->end = 0;

    return q;
}

int isEmpty(queue *q)
{
    assert(q != NULL);

    int isQueueEmpty = (q->size == 0);

    return isQueueEmpty;
}

int isFull(queue *q)
{
    assert(q != NULL);

    int isQueueFull = (q->size == QueueSize);

    return isQueueFull;
}

int insert(queue *q, elem x)
{
    if (isFull(q))
    {
        return 0;
    }

    q->items[q->end] = x;
    q->end = (q->end + 1) % QueueSize;
    q->size++;

    return 1;
}

int removeElement(queue *q, elem *x)
{
    if (isEmpty(q))
    {
        return 0;
    }

    *x = q->items[q->begin];
    q->begin = (q->begin + 1) % QueueSize;
    q->size--;

    return 1; 
}

void destroy(queue *q)
{
    if (q != NULL)
    {
        free(q);
    }
}