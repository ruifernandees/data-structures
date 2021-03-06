#include <stdio.h>
#include "swap.c"

void selectionSort(int arr[], int size)
{
    int min;

    for (int i = 0; i < size; i++) {
        min = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        swap(&arr[i], &arr[min]);
    }
}

void printArr(int arr[], int size)
{
    printf("Before:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    selectionSort(arr, size);

    printf("After:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

}

int main()
{
    int arr[7] = { -2, 3, -1, 5, 4, -3, 0 };
    printArr(arr, 7);

    int arr2[8] = { 4, 7, 2, 6, 4, 1, 8, 3 };
    printArr(arr2, 8);

    int arr3[4] = { 2, 2, 2, 2 };
    printArr(arr3, 4);

    int arr4[5] = { 2, 2, 2, 2, 2 };
    printArr(arr4, 5);

    
    return 0;
}
