#include <stdio.h>
#define MAX 50

typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
} REGISTER;

typedef struct {
    REGISTER A[MAX + 1];
    int numberOfElements;
} LIST;



void initStructure(LIST* list) {
    list->numberOfElements = 0;
}

int getSize(LIST* list) {
    return list->numberOfElements;
}

void showList(LIST* list) {
    printf("List: \" ");

    for (int i = 0; i < list->numberOfElements; i++) {
        printf("%i ", list->A[i].key);
    }

    printf(" \"\n");
}

int sequentialSearch(LIST* list, TYPEKEY key) {
    int i = 0;

    while (i < list->numberOfElements) {
        if (key == list->A[i].key) {
            return i;
        } else {
            i++;
        }
    }

    return -1;
}

int sentinelSearch(LIST* list, TYPEKEY key) {
    int i = 0;

    list->A[list->numberOfElements].key = key;

    while (list->A[i].key != key) {
        i++;
    }

    if (i == list->numberOfElements) {
        return -1;
    } else {
        return i;
    }
}

int insertListElement(LIST* list, REGISTER reg, int index) {
    if (
        list->numberOfElements == MAX
        || index < 0
        || index > list->numberOfElements
    ) {
        return 0;
    }

    for (int j = list->numberOfElements; j > index; j--) {
        list->A[j] = list->A[j - 1];
    }

    list->A[index] = reg;
    list->numberOfElements++;
    return 1;
}

int insertOrderedListElement(LIST* list, REGISTER reg) {
    if (list->numberOfElements >= MAX) {
        return 0;
    }

    int pos = list->numberOfElements;

    while (pos > 0 && list->A[pos - 1].key > reg.key) {
        list->A[pos] = list->A[pos - 1];
        pos--;
    }

    list->A[pos] = reg;
    list->numberOfElements++;
    return 1;
}

int removeListElement(LIST* list, TYPEKEY key) {

    int index = sequentialSearch(list, key);

    if (index == -1) return 0;

    if (
        list->numberOfElements <= 0
        || index < 0
        || index > list->numberOfElements
    ) {
        return 0;
    }

    for (int j = index; j < list->numberOfElements - 1; j++) {
        list->A[j] = list->A[j + 1];
    }

    list->numberOfElements--;
    return 1;
}

void rebootList(LIST* list) {
    list->numberOfElements = 0;
}