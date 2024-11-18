#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            ans += 1.0 / i;
        }
        if (i % 2 == 0) {
            ans -= 1.0 / i;
        }
    }
    printf("%.4f", ans);
    return 0;
}
