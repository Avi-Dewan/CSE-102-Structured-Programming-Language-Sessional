#include <stdio.h>

int LCM(int a, int b)
{
    int x = a, y = b;
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return (x*y/a);
}


int main()
{
    int lcm = 1, a;

    while(lcm <= 10000){
        scanf("%d", &a);
        lcm = LCM(lcm, a);
        printf("LCM of all numbers up to now is %d\n", lcm);
    }
    return 0;
}

