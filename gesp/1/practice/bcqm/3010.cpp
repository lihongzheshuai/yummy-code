#include <cstdio>
int main() {
    int a = 20, b = 22, c = 0;
    c = a;
    a = b;
    b = c;
    printf("a=%d\n", a);
    printf("b=%d", b);
    return 0;
}
