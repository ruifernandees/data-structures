#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
} REGISTER;

typedef struct aux {
    REGISTER reg;
    struct aux* next;
} ELEMENT;

typedef ELEMENT* POINT;

typedef struct {
    POINT begin;
} LIST;

void initLinkedList(LIST* list) {
    list->begin = NULL;
}

int getListSize(LIST* list) {
    POINT address = list->begin;
    int size = 0;

    while (address != NULL) {
        size++;
        address = address->next;
    }

    return size;
}

void showList(LIST* list) {
    POINT address = list->begin;
    printf("List: \" ");
    while(address != NULL) {
        printf("%i ", address->reg.key);
        address = address->next;
    }
    printf(" \"\n");
}

POINT sequentialSearch(LIST* list, TYPEKEY key) {
    POINT pos = list->begin;

    while (pos != NULL) {
        if (pos->reg.key == key) return pos;
        pos = pos->next;
    }

    return NULL;
}

POINT sequentialSearchExc(LIST* list, TYPEKEY key, POINT* previous) {
    *previous = NULL;
    POINT current = list->begin;

    while (
        current != NULL
        && current->reg.key < key
    ) {
        *previous = current;
        current = current->next;
    }

    if (current != NULL && current->reg.key == key) {
        return current;
    }
    return NULL;
}

bool insertListElement(LIST* list, REGISTER reg) {
    TYPEKEY key = reg.key;
    POINT previous, i;
    i = sequentialSearchExc(list, key, &previous);

    if (i != NULL) return 0;

    i = (POINT) malloc(sizeof(ELEMENT));
    i->reg = reg;

    if (previous == NULL) {
        i->next = list->begin;
        list->begin = i;
    } else {
        i->next = previous->next;
        previous->next = i;
    }
    return 1;
}

bool deleteListElement(LIST* list, TYPEKEY key) {
    POINT previous, i;
    i = sequentialSearchExc(list, key, &previous);

    if (i == NULL) return 0;

    if (previous == NULL) {
        list->begin = i->next;
    } else {
        previous->next = i->next;
    }
    free(i);
    return 1;
}

void rebootList(LIST* list) {
    POINT address = list->begin;

    while (address != NULL) {
        POINT clean = address;
        address = address->next;
        free(clean);
    }
    list->begin = NULL;
}
