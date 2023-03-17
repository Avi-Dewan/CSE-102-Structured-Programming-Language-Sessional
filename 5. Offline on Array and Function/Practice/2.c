#include <stdio.h>

int ans(int n, int m, int p)
{
    int x = 1;
    for(int i = 0; i < m; i++) {
        x = (x* (n%p)) % p;
    }

    return x;
}

int main()
{
    int n, m, p;

    scanf("%d%d%d", &n, &m, &p);

    int a = ans(n, m, p);

    printf("%d", a);

    return 0;

}
