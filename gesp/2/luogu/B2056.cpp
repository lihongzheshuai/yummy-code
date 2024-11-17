#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int a;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a;
    }
    printf("%d %.5f", ans, (double)ans / n);
    return 0;
}
