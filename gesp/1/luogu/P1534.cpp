#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b, c;
    int ans = 0;
    int y = 0;
    for (int i = 1; i <= a; i++) {
        cin >> b >> c;
        int t = (c + b) - 8;
        int t_1 = t + y;
        ans += t_1;
        y += t;
    }
    cout << ans;
    return 0;
}
