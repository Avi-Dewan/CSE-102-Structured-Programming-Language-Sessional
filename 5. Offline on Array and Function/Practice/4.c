#include <stdio.h>

int a[10000];

float median(int b[], int n)
{
    int c[10000];

    for(int i = 0; i < n; i++) c[i] = b[i];

    for(int i = 0; i < n-1; i++) {
        int index_min = i;
        for(int j = i + 1; j < n; j++) {
            if(c[j] < c[index_min]) {
                index_min = j;
            }
        }

        if(index_min != i) {
            int temp = c[i];
            c[i] = c[index_min];
            c[index_min] = temp;
        }
    }


    float x;

    if(n % 2 == 1) {
        x = c[n/2];
    } else {
        x = (c[n/2 - 1] + c[n/2])*1.0 / 2;
    }

    return x;

}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0;  i < n; i++) scanf("%d", &a[i]);

    float ans = median(a, n);

    float check = ans - (int)ans;

    if(check == 0) {
        printf("%d", (int)ans);
    } else {
        printf("%.1f", ans);
    }




}

