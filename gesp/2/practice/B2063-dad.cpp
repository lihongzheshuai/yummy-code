#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    double ans = pow(1.001, n) * x ;
    printf("%.4f", ans);
    return 0;
}
