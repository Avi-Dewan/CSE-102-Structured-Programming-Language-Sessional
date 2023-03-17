#include <stdio.h>

typedef struct _point{
    double x;
    double y
} Point;

typedef struct _parallelogram {
    Point A;
    Point B;
    Point D;
} Parallelogram;

Point addPoint(Point a, Point b) {
    Point pr;
    pr.x = a.x + b.x;
    pr.y = a.y + b.y;
    return pr;
}

Point subPoint(Point a, Point b) {
    Point pr;
    pr.x = a.x - b.x;
    pr.y = a.y - b.y;
    return pr;
}

Point scalePoint(Point a, double n) {
    Point pr;
    pr.x = a.x * n;
    pr.y = a.y * n;
    return pr;
}

Point findFourthPoint(Parallelogram p) {
    Point O;
    O = subPoint(addPoint(p.B, p.D), 0.5);
    Point C = addPoint(O, subPoint(O, p.A));

    return C;
}

int main()
{

}
