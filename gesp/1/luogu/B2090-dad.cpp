#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    double a;
    double ans = 0, bns = 0, cns = 0, dns = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a);
        if (a > 0 && a <= 18) {
            ans += 1;
        } else if (a >= 19 && a <= 35) {
            bns += 1;
        } else if (a >= 36 && a <= 60) {
            cns += 1;
        }
        if (a > 60) {
            dns += 1;
        }
    }
    printf("%.2f%%\n%.2f%%\n%.2f%%\n%.2f%%", (ans / n * 100), (bns / n * 100),
           (cns / n * 100), (dns / n * 100));
    return 0;
}
