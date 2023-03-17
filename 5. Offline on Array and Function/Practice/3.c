#include <stdio.h>

int a[10000] = {0};

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0;  i < n; i++) scanf("%d", &a[i]);

    for(int i = 0; i < n-1; i++) {
        int index_min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[index_min]) {
                index_min = j;
            }
        }

        if(index_min != i) {
            int temp = a[i];
            a[i] = a[index_min];
            a[index_min] = temp;
        }
    }

    if(n % 2 == 1) {
        printf("%d", a[n/2]);
    } else {
        float x = (a[n/2 - 1] + a[n/2])*1.0 / 2;
        printf("%.1f" ,x);
    }


}
