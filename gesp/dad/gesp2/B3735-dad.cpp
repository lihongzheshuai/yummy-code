#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    if (n == 1) {
        ans = 0;
    } else {
        ans = (2 + (n - 1) * 2) * (n - 1) / 2 + (n - 1);
    }
    cout << ans;
    return 0;
}