#include <stdio.h>

int checkPerfectNumber(int n) {

    if(n == 0) return 0;

    int s = 0;
    for(int i = 1; i < n; i++)
        if(n%i == 0) s += i;


    if(s == n) return 1;

    return 0;
}

int main()
{
    int n, sum = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        if(checkPerfectNumber(i))
            sum += i;

    printf("%d", sum);

    return 0;

}
