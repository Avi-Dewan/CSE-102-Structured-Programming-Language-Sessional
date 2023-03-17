#include <stdio.h>

int factorial(int x)
{
    int fact = 1;
    for(int i = 2; i <= x; i++) fact *= i;

    return fact;

}

int main()
{
    int n;
    int ans = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i += 2) {
        ans += factorial(i);
    }

    printf("%d", ans);

    return 0;
}
