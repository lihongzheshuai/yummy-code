#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int a = 1, b = 2;
    double q = b / a;
    for (int i = 1; i <= n; i++) {
        q += (b + 1) / (a + 1);
    }
    printf("%4f", q);
    return 0;
}
