#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int d;
    long long ans = 0;
    for (int i = 0; i < a; i++) {
        cin >> d;
        if (d % 2 == 0) {
            ans += d;
        }
    }
    cout << ans;
    return 0;
}
