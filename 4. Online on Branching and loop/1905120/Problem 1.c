#include <stdio.h>

int main()
{
    int H, W, T;

    scanf("%d%d", &H, &W);

    T = W;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            printf("*");
        }
        printf("\n");
        if(i % 2 == 0) W += T;
    }

    for(int i = H; i >= 1; i--) {
        for(int j = W; j >= 1; j--) {
            printf("*");
        }
        printf("\n");
        if(i % 2 == 1) W -= T;
    }

    return 0;
}
