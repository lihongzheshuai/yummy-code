#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int ans = 1;
    for (int i = 1; i <= b; i++) {
        int u = ans * a;
        ans = u % 1000;
    }
    printf("%03d", ans);
    return 0;
}
