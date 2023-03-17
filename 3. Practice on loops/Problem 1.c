#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, ans;
    scanf("%lf", &x);

    x = (x*1.0/180) * 3.14159;

    ans = 0;

    for(int i = 0; i < 30; i++) {
        y = pow(x, 2*i+1) * pow(-1, i);

        for(int j = 2; j <= 2*i + 1; j++ ) {
            y /= j;
        }
        ans += y;
    }

    printf("%.6lf", ans);
}
