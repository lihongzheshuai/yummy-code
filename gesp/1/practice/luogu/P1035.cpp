#include <cstdio>
int main() {
    int k;
    scanf("%d", &k);
    int n = 0;
    for (double a = 0; a <= k; a += 1.0 / n) {
        n++;
    }
    printf("%d", n);
    return 0;
}
