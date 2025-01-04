#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    cin >> n;
    double ans = 1;
    for (int i = 1; i <= n; i++) {
        double tmp = 0;
        long long denominator = 1;
        for (int j = 1; j <= i; j++) {
            denominator *= j;
        }
        tmp = 1.0 / denominator;
        ans += tmp;
    }
    printf("%.10f", ans);
    return 0;
}