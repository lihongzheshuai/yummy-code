#include <cstdio>
int main() {
    int a;
    scanf("%d", &a);
    // 100������
    int b = a / 100;
    int rest = a - b * 100;
    printf("%d\n", b);
    // 50 ������
    int c = rest / 50;
    rest = rest - c * 50;
    printf("%d\n", c);
    // 20 ������
    int d = rest / 20;
    rest = rest - d * 20;
    printf("%d\n", d);
    // 10 ������
    int e = rest / 10;
    rest = rest - e * 10;
    printf("%d\n", e);
    // 5 ������
    int f = rest / 5;
    rest = rest - f * 5;
    printf("%d\n", f);
    // 1 ������
    printf("%d", rest);
    return 0;
}
