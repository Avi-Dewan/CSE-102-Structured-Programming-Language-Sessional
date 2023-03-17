#include <stdio.h>

int main()
{
    int r1, r2, c1, c2;
    int a[5][5] = {0}, b[5][5] = {0};

    scanf("%d%d", &r1, &c1);

    for(int i = 0; i < r1; i++)
        for(int j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    scanf("%d%d", &r2, &c2);

    for(int i = 0; i < r2; i++)
        for(int j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);
    if(c1 == r2) {
        printf("%d %d\n", r1, c2);
        for(int i = 0; i < r1; i++) {
            for(int j = 0; j < c2; j++) {
                int x = 0;
                for(int k = 0; k < c1; k++) {
                    x += a[i][k]*b[k][j];
                }
                printf("%d ", x);
            }
            printf("\n");
        }
    } else
        printf("Multiplication not possible\n");

    return 0;

}
