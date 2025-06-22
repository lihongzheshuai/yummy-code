#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int x, y, z;
    cin >> x >> y >> z;
    int m = min(x, min(y, z));
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        if (x % i == 0 && y % i == 0 && z % i == 0) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}