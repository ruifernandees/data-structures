#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

struct element {
    void *item;
    struct element *next;
};

struct stack {
    ELEMENT_POINT top;
    int elementSize;
    int size;
};

tStack *createStack(int elementSize)
{
    tStack *p = (tStack *) malloc(sizeof(tStack));
    p->top = NULL;
    p->elementSize = elementSize;
    p->size = 0;
    return p;
}

void destroy(tStack *p)
{
    while (p->top != NULL)
    {
        void *nextItem = p->top->next;
        free(p->top->item);
        free(p->top);
        p->top = nextItem;
    }

    if (p != NULL)
    {
        free(p);
    }

    p = NULL;
}

int stackSize(tStack *p)
{
    return p->size;
}

int isEmpty(tStack *p)
{
    assert(p != NULL);
    int isStackEmpty = (p->top == NULL);

    return isStackEmpty;
}

int push(tStack *p, void *elem)
{
    assert(p != NULL);

    ELEMENT_POINT e = (ELEMENT_POINT) malloc(sizeof(ELEMENT));
    e->item = (void *) malloc(sizeof(p->elementSize));

    assert(e->item != NULL);
    memcpy(e->item, elem, p->elementSize);
    e->next = p->top;
    p->top = e;
    p->size++;

    assert(p->top != NULL);

    return 1;
}

int pop(tStack *p, void *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    memcpy(elem, p->top->item, p->elementSize);
    p->top = p->top->next;
    p->size--;


    return 1;
}

int top(tStack *p, void *elem)
{
    assert(p != NULL);

    if (isEmpty(p))
    {
        return 0;
    }

    memcpy(elem, p->top, p->elementSize);

    return 1;
}