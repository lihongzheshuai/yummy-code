#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans += a;
    }
    printf("%.2f", (double)ans / (double)n);
    return 0;
}
