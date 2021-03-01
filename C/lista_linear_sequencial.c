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

int main() {
    void initStructure(LIST* list);
    int getSize(LIST* list);
    void showList(LIST* list);
    int sequentialSearch(LIST* list, TYPEKEY key);
    int sentinelSearch(LIST* list, TYPEKEY key);
    int insertListElement(LIST* list, REGISTER reg, int index);
    int removeListElement(LIST* list, TYPEKEY key);
    void rebootList(LIST* list);

    LIST myList;
    initStructure(&myList);

    REGISTER register1 = { 10 };
    REGISTER register2 = { 15 };
    REGISTER register3 = { 20 };

    insertListElement(&myList, register1, 0);
    insertListElement(&myList, register2, 0);
    insertListElement(&myList, register3, 0);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("10 is %d\n", sentinelSearch(&myList, 10));
    printf("15 is %d\n", sentinelSearch(&myList, 15));
    printf("20 is %d\n\n\n", sentinelSearch(&myList, 20));

    removeListElement(&myList, 10);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));

    printf("10 is %d\n", sentinelSearch(&myList, 10));
    printf("20 is %d\n\n\n", sentinelSearch(&myList, 20));

    rebootList(&myList);

    showList(&myList);
    printf("Size: %d\n\n", getSize(&myList));
    
    return 0;
}

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

    for (int j = index; j < list->numberOfElements; j++) {
        list->A[j - 1] = list->A[j];
    }

    list->numberOfElements--;
    return 1;
}

void rebootList(LIST* list) {
    list->numberOfElements = 0;
}