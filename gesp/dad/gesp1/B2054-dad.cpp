#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double ans = 0;
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a;
    }
    printf("%.2f", ans / n);
    return 0;
}
