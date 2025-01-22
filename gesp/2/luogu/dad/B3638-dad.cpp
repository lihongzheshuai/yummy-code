#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a, b, c;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double tmp = (a + b + c) / 2;
    double s = sqrt(tmp * (tmp - a) * (tmp - b) * (tmp - c));
    printf("%.0f", s);
    return 0;
}