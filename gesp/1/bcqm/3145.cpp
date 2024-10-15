#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int i = 0;
    for (m; m <= n; m++) {
        if (m % 2 != 0) {
            i += m;
        }
    }
    cout << i;
    return 0;
}
