#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int nmax = 0, nmin = 10;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        nmax = max(x, nmax);
        nmin = min(x, nmin);
    }
    sum = sum - nmax - nmin;
    printf("%.2lf", (double)sum / (n - 2));
    return 0;
}