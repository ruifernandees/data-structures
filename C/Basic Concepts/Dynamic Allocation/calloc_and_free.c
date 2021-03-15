#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    int n;

    scanf("%d", &n) ;

    p = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    free(p);

    return 0;
}