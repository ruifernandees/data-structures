#include <stdio.h>

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void printArr(int arr[], int size)
{
    printf("Before:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size);

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