#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int** a, int m, int n) {
    for(int i = 0;  i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", *(a+i) + j);

}

int main()
{
    int m, n, x, c = 0;
    scanf("%d%d", &m, &n);

    int **a = (int**)malloc(n*sizeof(int*));


    for(int i = 0; i < n; i++)
        *(a+i) = (int*)malloc(m*sizeof(int));

    inputMatrix(a, m, n);

    scanf("%d", &x);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(*(*(a+i) + j) == x) {
                printf("%d %d\n", i+1, j+1);
                c = 1;
            }
        }

    if(!c) printf("-1");

    return 0;
}
