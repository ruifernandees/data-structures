#include <stdio.h>

void swap(int* number1, int* number2)
{
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

int partition(int arr[], int begin, int end) 
{
    int pivot = arr[end];
    int i = begin - 1;

    for (int j = begin; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[end]);

    return i + 1;
}

void quickSort(int arr[], int begin, int end) 
{
    if (begin >= end) return;

    int p = partition(arr, begin, end);

    quickSort(arr, begin, p - 1);
    quickSort(arr, p + 1, end);
}

void printArr(int arr[], int size)
{
    printf("Before:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, size - 1);

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