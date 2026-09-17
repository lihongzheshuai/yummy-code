#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int i = n / 2;
    if (n % 2 != 0) {
        i += 1;
    }
    printf("%d", i);
    return 0;
}
