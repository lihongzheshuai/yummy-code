#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b;
    int ans = 1;
    for (int i = 1; i <= a; i++) {
        cin >> b;
        ans *= b;
        if (ans <= 1000000) {
            continue;
        } else {
            cout << ">1000000";
            return 0;
        }
    }
    cout << ans;
    return 0;
}