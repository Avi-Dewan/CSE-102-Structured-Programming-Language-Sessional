#include <stdio.h>

typedef struct _complex{
    float x;
    float y;
} Complex;

void printComplex(Complex X) {
    printf("%.2f", X.x);

    if(X.y >= 0) printf("+");

    printf("%.2fi\n", X.y);
}

Complex multiplyComplex(Complex X, Complex Y) {
    Complex Z;
    Z.x = X.x * Y.x - X.y * Y.y;
    Z.y = X.x * Y.y + X.y * Y.x;

    return Z;
}

Complex divideComplex(Complex X, Complex Y) {
    Complex Z;

    Complex Yc = Y;
    Yc.y = -1 * Yc.y;


    float div = Y.x * Y.x + Y.y * Y.y;

    Complex M = multiplyComplex(X, Yc);

    Z.x = M.x *1.0 / div;
    Z.y = M.y * 1.0 / div;


    return Z;
}

int main()
{
    Complex X , Y, Multi, Div;

    scanf("%f%f%f%f", &X.x, &X.y, &Y.x, &Y.y);

    Multi = multiplyComplex(X, Y);
    Div = divideComplex(X, Y);

    printComplex(Multi);
    printComplex(Div);



    return 0;
}
