#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

struct stack {
    int top;
    void **items;
    int elementSize;
};

tStack *createStack(int elementSize)
{
    tStack *p = (tStack *) malloc(sizeof(tStack));
    assert(p != NULL);

    p->items = (void **) malloc(sizeof(void *) * StackSize);

    p->top = -1;
    p->elementSize = elementSize;

    return p;
}

void destroy(tStack *p)
{
    while (p->top >= 0)
    {
        free(p->items[p->top]);
        p->top--;
    }

    if (p->items != NULL)
    {
        free(p->items);
    }

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

int push(tStack *p, void *elem)
{
    assert(p != NULL);

    if (isFull(p))
    {
        return 0;
    }

    p->top++;

    p->items[p->top] = (void *) malloc(sizeof(p->elementSize));

    assert(p->items[p->top] != NULL);
    memcpy(p->items[p->top], elem, p->elementSize);

    return 1;
}

int pop(tStack *p, void *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    memcpy(elem, p->items[p->top], p->elementSize);
    free(p->items[p->top]);

    p->top--;

    return 1;
}

int top(tStack *p, void *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    memcpy(elem, p->items[p->top], p->elementSize);

    return 1;
}