#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int ans = (a + b) % 7;
    if (ans == 0) {
        ans = 7;
    }
    cout << ans;
    return 0;
}
