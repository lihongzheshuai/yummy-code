#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    int x;
    cin >> x;
    cin >> n;
    double a = (int)x;
    for (int i = 1; i <= n; i++) {
        a += a * 0.001;
    }
    printf("%.4f", a);
    return 0;
}
