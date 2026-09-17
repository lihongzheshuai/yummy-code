#include <cstdio>
int main() {
    int a = 0;
    for (int i = 1; i <= 5; i++) {
        // 从第一天开始，每天刻痕数+1
        a += 1;
    }
    printf("%d", a);
    return 0;
}