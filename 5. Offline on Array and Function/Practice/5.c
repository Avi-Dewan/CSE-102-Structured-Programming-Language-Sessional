#include <stdio.h>

int a[10000];

int check_prime(int n)
{
    for(int i = 2; i*i < n; i++) {
        if(n%i == 0) return 0;
    }

    return 1;
}

int main()
{
    int n;

    while(1) {
        scanf("%d", &n);

        if(n == -1) break;

        int x = n;



        if(a[n] != 0) {
            printf("%d\n", a[n]);
            continue;
        }

        if(check_prime(n)) {
            printf("0\n");
            continue;
        }

        int i = 2;

        while(i <= n)
        {

            while(n % i == 0) {
                a[i]++;
                n = (n/i);
            }
            i++;
        }

        int j = 0;

        for(int m = 2; m <= x; m++) {
            if(a[m] == 1) {
                    printf("%d", m);
                    j = m+1;
                    break;
            }
            else if(a[m] > 1) {
                    printf("%d^%d", m, a[m]);
                    j = m + 1;
                    break;
            }
        }

        if(j != 0) {
            while(j < x) {
                if(a[j] != 0) {
                    printf(" X %d^%d", j, a[j]);
                }
                j++;
            }
        }

        printf("\n");

    }

    return 0;
}
