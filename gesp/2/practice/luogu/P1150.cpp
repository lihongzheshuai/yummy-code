#include <iostream>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        if (i % k == 0) {
            n++;
        }
        ans += 1;
    }
    cout << ans;
    return 0;
}
