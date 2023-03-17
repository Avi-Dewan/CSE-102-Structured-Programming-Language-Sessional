#include <stdio.h>

int countOne(int n)
{
    int c = 0;
    while(n != 0) {
        if(n%2 == 1) c++;

        n /= 2;
    }

    return c;
}

int factor(int n) {
    int c = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) c++;
    }

    return c;
}

void sort(int A[], int one[], int fact[], int n)
{
    int i, j, index_min, temp1, temp2, temp3;

    for(i = 0; i < n-1; i++) {
        index_min = i;
        for(j = i+1; j < n; j++) {
            if(one[j] < one[index_min]) {
                index_min = j;
            } else if(one[j] == one[index_min]) {
                if(fact[j] > fact[index_min]) {
                    index_min = j;
                } else if(fact[j] == fact[index_min]) {
                    if(A[j] < A[index_min])
                        index_min = j;
                }
            }
        }
        if(index_min != i) {
            temp1 = A[i];
            temp2 = one[i];
            temp3 = fact[i];
            A[i] = A[index_min];
            one[i] = one[index_min];
            fact[i] = fact[index_min];
            A[index_min] = temp1;
            one[index_min] = temp2;
            fact[index_min] = temp3;
        }
    }
}

int main()
{
    int a[1000] = {0}, one[1000] = {0}, fact[1000] = {0};

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    for(int i = 0; i < n; i++) one[i] = countOne(a[i]);

    for(int i = 0; i < n; i++) fact[i] = factor(a[i]);


    sort(a, one, fact, n);

    for(int i = 0; i < n; i++) printf("%d ", a[i]);

    return 0;
}
