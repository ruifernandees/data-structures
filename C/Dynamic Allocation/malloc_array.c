#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *p;
    int n;
    scanf("%d", &n);

    p = (float *) malloc(sizeof(float) * n);

    for (int i = 0 ; i < n; i++) {
        // *(p + i) = 1.0;
        p[i] = 1.0;
    }

    for (int j = 0; j < n; j++) {
        // printf("%.2lf\n", *(p + j));
        printf("%.2lf\n", p[j]);
    }

    return 0;
}