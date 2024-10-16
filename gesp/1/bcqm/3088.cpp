#include <cstdio>
int main() {
    double a;
    scanf("%lf", &a);
    if (a <= 20) {
        printf("%.2f", a * 1.68);
    } else {
        printf("%.2f", a * 1.98);
    }
    return 0;
}
