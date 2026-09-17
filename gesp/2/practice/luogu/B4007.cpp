#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int che = i;
        while (che != 0) {
            int z = che % 10;
            if (z == k) {
                ans++;
            }
            che /= 10;
        }
    }
    cout << ans;
    return 0;
}
