#include <cstdio>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (int i = a + 1; i < b; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            ans += i;
        }
    }
    printf("%d", ans);
    return 0;
}