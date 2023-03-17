#include <stdio.h>
#include <stdlib.h>

int* printArray(int *a, int n) {
    int *m = a, i = 0;
    while(i < n) {
        *m = 2* i + 1;
        i++;
        m++;
    }
    return a;// Actually, no need to return. As we're working on memory level
}



int main()
{
    int n;

    scanf("%d", &n);

    int *a = (int*)malloc(n*sizeof(int));

    printArray(a, n);

    for(int i = 0 ; i < n; i++) {
        printf("%d\n", *(a+i));
    }

    free(a);
}
