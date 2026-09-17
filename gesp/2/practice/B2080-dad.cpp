#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    double x;
    cin >> x >> n;
    double ans = 1;
    for (int i = 1; i <= n; i++) {
        double power = pow(x,i);
        ans += power;
    }
    printf("%.2f", ans);
    return 0;
}
