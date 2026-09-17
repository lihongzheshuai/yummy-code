#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int max;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            max = i;
        }
    }
    cout << max;
    return 0;
}
