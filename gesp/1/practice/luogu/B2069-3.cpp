#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int m = 1;
    int z = 2;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (double)z / m;
        int temp = z;
        z = m + z;
        m = temp;
    }
    printf("%.4f", sum);

    return 0;
}
