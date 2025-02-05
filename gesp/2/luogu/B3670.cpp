#include <iostream>
using namespace std;
int main() {
    int n, r;
    cin >> n >> r;
    int k, p;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k >> p;
        if (k > max && p <= r) {
            max = k;
        }
    }
    cout << max;
    return 0;
}
