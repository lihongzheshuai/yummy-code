#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    int ans = x % 2023;
    if (x >= 0) {
        cout << ans;
    } else {
        cout << ans + 2023;
    }
    return 0;
}
