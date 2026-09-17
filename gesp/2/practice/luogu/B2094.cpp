#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    int a;
    int max = 0;
    int max_times = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (i == 1) {
            max = a;
            max_times = 1;
        } else {
            if (a > max) {
                max = a;
                max_times = 1;
            } else if (a == max) {
                max_times++;
            }
        }
        ans += a;
    }
    cout << ans - max * max_times;
    return 0;
}
