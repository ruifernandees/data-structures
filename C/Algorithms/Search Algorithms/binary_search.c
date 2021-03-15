#include <stdio.h>

int binarySearch(int *v, int size, int element)
{
    int begin = 0;
    int end = size - 1;
    int middle;

    while (begin <= end) {
        middle = (begin + end) / 2;

        if (v[middle] < element) {
            begin = middle + 1;
        } else if (v[middle] > element) {
            end = middle - 1;
        } else {
            return middle;
        }
    }

    return -1;
}

int main()
{
    // The array needs to be ordered
    int numbers[7] = { 12, 23, 45, 67, 99, 101, 212 };

    printf("Index of %d: %d\n", 99, binarySearch(numbers, 7, 99));

    return 0;
}