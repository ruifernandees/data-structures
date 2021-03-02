#include <stdio.h>
#define MAX 50
#define INVALID -1

typedef int TYPEKEY;

typedef struct {
    TYPEKEY key;
} REGISTER;

typedef struct {
    REGISTER reg;
    int next;
} ELEMENT;

typedef struct {
    ELEMENT arr[MAX];
    int begin;
    int indexOfFirstAvailableElement;
} LIST;

/**
 * Colocar todos os elementos na lista de disponíveis
 * Acertar a variávelindexOfFirstAvailableElement 
 * Acertar a variável begin (para indicar que não há item válido)
 */
void initLinkedList(LIST* list) {
    int i;

    /**
     * Example of the goal: {
     *      [ -, -, -, -,  - ]  <- REGISTER key
     *      [ 1, 2, 3, 4, -1 ]  <- ELEMENT next
     * }
     */
    for (i = 0; i < MAX - 1; i++) {
        list->arr[i].next = i + 1;
    }

    // Last element of the list
    list->arr[MAX - 1].next = INVALID;
    list->begin = INVALID;
    list->indexOfFirstAvailableElement = 0;
}

int getListSize(LIST* list) {
    int i = list->begin;
    int size = 0;
    
    // Count valid elements
    while (i != INVALID) {
        size++;
        i = list->arr[i].next;
    }

    return size;
}

void showList(LIST* list) {
    int i = list->begin;

    printf("List: \" ");

    while (i != INVALID) {
        printf("%i ", list->arr[i].reg.key);
        i = list->arr[i].next;
    }

    printf(" \"\n");
}

/**
 * Get a key from user
 * Return the position where the element is in the array if it is found
 * Return INVALID if it is not found
 */
int sequentialOrderedSearch(LIST* list, TYPEKEY key)  {
    int i = list->begin;

    /**
     * Example (search by 6): {
     *      [ 5,  9, -, 7,  - ]  <- REGISTER key
     *      [ 3, -1, -, 1, - ]  <- ELEMENT next
     * }
     * 1st iteration: i == 0; list->arr[i].reg.key == 5 (not found)
     * 2nd iteration: i == 3; list->arr[i].reg.key == 7 (not found and stop iteration because we dont have elements after 7 that is equal to 6)
     */

    while (i != INVALID && list->arr[i].reg.key < key) {
        i = list->arr[i].next;
    }

    if (i != INVALID && list->arr[i].reg.key == key) {
        return i;
    }

    return INVALID;
}

/**
 *  Removes the first element of the available list 
 *  Returns its index on the array
 */ 
int getNode(LIST* list) {
    int result = list->indexOfFirstAvailableElement;

    if (list->indexOfFirstAvailableElement != INVALID) {
        list->indexOfFirstAvailableElement = list->arr[list->indexOfFirstAvailableElement].next;
    }

    return result;
}

int insertElementLinkedList(LIST* list, REGISTER reg) {
    if (list->indexOfFirstAvailableElement == INVALID) {
        return 0;
    }

    int previous = INVALID;
    int i = list->begin;
    TYPEKEY key = reg.key;

    /**
     * p == -1; i == 0;
     * p == 0; i == 3;
     * p == 3; i == 1;
     */
    while (
        i != INVALID
        && list->arr[i].reg.key < key
    ) {
        previous = i;
        i = list->arr[i].next;
    }

    if (i != INVALID && list->arr[i].reg.key == key) {
        return 0;
    }

    i = getNode(list);
    list->arr[i].reg = reg;

    if (previous == INVALID) {
        list->arr[i].next = list->begin;
        list->begin = i;
    } else {
        list->arr[i].next = list->arr[previous].next;
        list->arr[previous].next = i;
    }
    return 1;

}

void getNodeBack(LIST* list, int j) {
    list->arr[j].next = list->indexOfFirstAvailableElement;
    list->indexOfFirstAvailableElement = j;
}

int deleteListElement(LIST* list, TYPEKEY key) {
    int previous = INVALID;
    int i = list->begin;

    while(
        i != INVALID
        && list->arr[i].reg.key < key
    ) {
        previous = i;
        i = list->arr[i].next;
    }

    if (i == INVALID || list->arr[i].reg.key != key) {
        return 0;
    }

    // Change the pointers
    if (previous == INVALID) {
        list->begin = list->arr[i].next;
    } else {
        list->arr[previous].next = list->arr[i].next;
    }
    getNodeBack(list, i);
    return 1;
}

void rebootLinkedList(LIST* list) {
    initLinkedList(list);
}