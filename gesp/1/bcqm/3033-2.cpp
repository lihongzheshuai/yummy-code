#include <cstdio>
int main() {
    int a;
    scanf("%d", &a);
    // 100的张数
    int b = a / 100;
    int rest = a % 100;
    printf("%d\n", b);
    // 50 的张数
    int c = rest / 50;
    rest = rest % 50;
    printf("%d\n", c);
    // 20 的张数
    int d = rest / 20;
    rest = rest % 20;
    printf("%d\n", d);
    // 10 的张数
    int e = rest / 10;
    rest = rest % 10;
    printf("%d\n", e);
    // 5 的张数
    int f = rest / 5;
    rest = rest % 5;
    printf("%d\n", f);
    // 1 的张数
    printf("%d", rest);
    return 0;
}
