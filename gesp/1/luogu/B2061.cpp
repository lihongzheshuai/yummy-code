#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k;
    int ans = 0;
    int bns = 0;
    int cns = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        if (k == 1) {
            ans += 1;
        }
        if (k == 5) {
            bns += 1;
        }
        if (k == 10) {
            cns += 1;
        }
    }
    cout << ans << endl;
    cout << bns << endl;
    cout << cns;
    return 0;
}
