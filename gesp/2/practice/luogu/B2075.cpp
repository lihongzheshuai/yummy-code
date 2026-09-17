#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int ans = a;
    for (int i = 1; i <= b - 1; i++) {
        int u = ans * a;
        int e = u / 10 / 10 % 10 * 100;
        int w = u / 10 % 10 * 10;
        int o = u % 10;
        ans = e + w + o;
    }
    printf("%03d", ans);
    return 0;
}
