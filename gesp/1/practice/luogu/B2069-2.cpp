#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int m1 = 1;
    int m2 = 2;
    int z1 = 2;
    int z2 = 3;
    int m;
    int z;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            z = z1;
            m = m1;

        } else if (i == 2) {
            z = z2;
            m = m2;
        } else {
            m = m1 + m2;
            m1 = m2;
            m2 = m;
            z = z2 + z1;
            z1 = z2;
            z2 = z;
        }
        sum += (double)z / m;
    }
    printf("%.4f", sum);

    return 0;
}
