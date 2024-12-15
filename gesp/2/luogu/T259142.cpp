<<<<<<< HEAD
#include <iostream>
using namespace std;
int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) { // 外层循环
        int tmp = i, num;
        while (tmp != 0) { // 内层循环
            num = tmp % 10;
            if (num == x)
                ans++;
            tmp = tmp / 10;
        }
    }
    cout << ans;
=======
#include <cstdio>
int main() {
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    for (int i = 1; i <= a; i++) {
        int d = i;
        while (d != 0) {
            ans = d % 10;
            if (ans == b) {
                ans++;
                d = d / 10;
            }
        }
    }
    printf("%d", ans);
>>>>>>> 923c7674fc12a74a406700b562b30e44ceac0609
    return 0;
}

