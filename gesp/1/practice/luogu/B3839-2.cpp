#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n - (i - 1)) * i;
    }
    cout << ans;
    return 0;
}
