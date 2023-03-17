#include <stdio.h>

int main()
{
    int a[5][5] = {0};
    int n, t;

    scanf("%d", &n);

    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }

     for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n/2; j++) {
            t = a[i][j];
            a[i][j] = a[i][n-1-j];
            a[i][n-1-j] = t;
        }
     }

     for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++)
           printf("%d ", a[i][j]);
        printf("\n");
     }

}
