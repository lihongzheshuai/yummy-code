#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    double x;
    cin >> x >> n;
    double ans = 1;

    ans += x * (1 - pow(x, n)) / (1 - x);

    printf("%.2f", ans);
    return 0;
}
