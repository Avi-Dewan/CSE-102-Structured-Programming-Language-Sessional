#include<stdio.h>

int main()
{
    int a[20003] = {0};

    int n, max = 1, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        x += 10000;
        a[x]++;

        if(a[x] > max) max = a[x];

        printf("Most frequent number = ");

        int check = 0;

        for(int i = 0; i < 20001; i++) {
            if(check == 0) {
                if(a[i] == max) {
                    printf("%d", i-10000);
                    check = 1;
                }
            } else {
                if(a[i] == max)
                    printf(", %d", i-10000);

            }

        }

        printf("\n");

    }

    return 0;
}
