#include <stdio.h>

void merge(int arr[], int begin, int middle, int end)
{
    int sizeLeft = middle - begin;
    int sizeRight = end - middle;

    int left[sizeLeft];
    int right[sizeRight];

    for (int i = 0; i < sizeLeft; i++) {
        left[i] = arr[begin + i];
    }
    for (int i = 0; i < sizeRight; i++) {
        right[i] = arr[middle + i];
    }

    // Top because you can think that it is like the top of a stack of elements
    int topLeft = 0;
    int topRight = 0;

    int k = begin;

    while (k < end) {            
        if (topLeft >= sizeLeft) 
        {
            arr[k] = right[topRight];
            topRight++;
        } 
        else if (topRight >= sizeRight) 
        {
            arr[k] = left[topLeft];
            topLeft++;
        }
        else if (left[topLeft] < right[topRight]) 
        {
            arr[k] = left[topLeft];
            topLeft++;
        }
        else 
        {
            arr[k] = right[topRight];
            topRight++;
        }
        k++;
    }
}


/**
 * begin -> first index
 * end -> size
 */
void mergeSort(int arr[], int begin, int end)
{
    /**
     * Example:
     * [4, 7, 2, 6, 5]
     * begin = 0
     * end = 5
     */
    if (end - begin > 1) {
        int middle = (begin + end) / 2;
        mergeSort(arr, begin, middle); 
        // [4, 7]
        // [4] and [7]
        // merge: [4, 7]

        mergeSort(arr, middle, end); 
        // [2, 6, 5]
        // [2] and [6, 5]
        // [2], [6] and [5]
        // [2] and merge: [5, 6]
        // merge: [2, 5, 6]


        merge(arr, begin, middle, end);
        // merge: [2, 4, 5, 6, 7]
    }
}

void printArr(int arr[], int size)
{
    printf("Before:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    mergeSort(arr, 0, size);

    printf("After:\t\t");
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");

}

int main()
{
    int size;

    int arr[7] = { -2, 3, -1, 5, 4, -3, 0 };
    size = 7;

    printArr(arr, size);

    int arr2[5] = { 4, 7, 2, 6, 5 };
    size = 5;
    printArr(arr2, size);

    int arr3[8] = { 4, 7, 2, 6, 4, 1, 8, 3 };
    size = 8;
    printArr(arr3, size);

    int arr4[4] = { 2, 2, 2, 2 };
    printArr(arr4, 4);

    int arr5[5] = { 2, 2, 2, 2, 2 };
    printArr(arr5, 5);


    return 0;
}