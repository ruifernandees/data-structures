#include <stdio.h>
#include <malloc.h>

typedef int bool;
typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
} REGISTER;

typedef struct tempRegister {
    REGISTER reg;
    struct tempRegister* next;
} ELEMENT;

typedef ELEMENT* POINT;

typedef struct {
    POINT head;
} LIST;

void initList(LIST* list) {
    list->head = (POINT) malloc(sizeof(ELEMENT));
    list->head->next = list->head;
}

int getListSize(LIST* list) {
    POINT address = list->head->next;
    int size = 0;

    while (address != list->head) {
        size++;
        address = address->next;
    }

    return size;
}

void showList(LIST* list) {
    POINT address = list->head->next;

    printf("List: \"");

    while (address != list->head) {
        printf("%i ", address->reg.key);
        address = address->next;
    }

    printf(" \"\n");
}

POINT sentinelSearch(LIST* list, TYPEKEY key) {
    POINT pos = list->head->next;
    list->head->reg.key = key;

    while (pos->reg.key != key) {
        pos = pos->next;
    }

    if (pos != list->head) {
        return pos;
    }

    return NULL;
}

POINT sequentialSearchExc(LIST* list, TYPEKEY key, POINT* previous) {
    *previous = list->head;
    POINT current = list->head->next;

    list->head->reg.key = key;

    while(current->reg.key < key) {
        *previous = current;
        current = current->next;
    }

    if (current != list->head && current->reg.key == key) {
        return current;
    }
    
    return NULL;
}

bool insertOrderedListElement(LIST* list, REGISTER reg) {
    POINT previous, i;

    i = sequentialSearchExc(list, reg.key, &previous);

    if (i != NULL) {
        return 0;
    }

    i = (POINT) malloc(sizeof(ELEMENT));
    i->reg = reg;
    i->next = previous->next;
    previous->next = i;

    return 1;
}

bool deleteListElement(LIST* list, TYPEKEY key) {
    POINT previous, i;
    i = sequentialSearchExc(list, key, &previous);

    if (i == NULL) return 0;

    previous->next = i->next;
    free(i);
    return 1;
}

void listReboot(LIST* list) {
    POINT address = list->head->next;

    while (address != list->head) {
        POINT clear = address;
        address = address->next;
        free(clear);
    }
    list->head->next = list->head;
}