#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **p;
    int lines, columns;

    scanf("%d %d", &lines, &columns);

    p = (int **) malloc(sizeof(int *) * lines);

    for (int i = 0; i < lines; i++) {
        p[i] = (int *) malloc(sizeof(int) * columns);
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < lines; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}