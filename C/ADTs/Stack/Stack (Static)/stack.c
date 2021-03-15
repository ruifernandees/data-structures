#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct stack {
    int top;
    element items[StackSize];
};

tStack *createStack()
{
    tStack *p = (tStack *) malloc(sizeof(tStack));

    assert(p != NULL);

    p->top = -1;

    return p;
}

void destroy(tStack *p)
{
    if (p != NULL)
    {
        free(p);
    }

    p = NULL;
}

int isFull(tStack *p)
{
    assert(p != NULL);
    int isStackFull = (p->top == StackSize - 1);
    return isStackFull;
}

int isEmpty(tStack *p)
{
    assert(p != NULL);
    int isStackEmpty = (p->top == -1);

    return isStackEmpty;
}

int push(tStack *p, element elem)
{
    assert(p != NULL);

    if (isFull(p))
    {
        return 0;
    }

    p->top++;

    p->items[p->top] = elem;

    return 1;
}

int pop(tStack *p, element *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    *elem = p->items[p->top];

    p->top--;

    return 1;
}

int top(tStack *p, element *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    *elem = p->items[p->top];

    return 1;
}