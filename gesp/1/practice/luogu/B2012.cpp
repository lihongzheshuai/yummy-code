#include <cstdio>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%.3f%%", (double)b / (double)a * 100.0);
    return 0;
}
