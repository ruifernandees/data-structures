#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char *) malloc(sizeof(char));
    char c;
    int i = 0;    

    printf("Type some string and press enter: \n");
    printf("=> ");
    while ((c = getchar()) != '\n') {
        str[i] = c;
        i++;
        str = (char *) realloc(str, sizeof(char) * (i + 1));
    }
    str[i] = '\0';
    
    printf("%s, %lu\n", str, sizeof(str));
    free(str);

    return 0;
}