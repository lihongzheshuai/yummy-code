#include <cstdio>
using namespace std;
int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (d < b) {
        printf("%d %d", c - 1 - a, d + 60 - b);
    } else {
        printf("%d %d", c - a, d - b);
    }
    return 0;
}