#include <iostream>
using namespace std;
int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    if (k / 60 >= 1) {
        m += k / 60;
        s += k % 60;
    } else if (s + k > 60) {
        s += k -= 60;
        m += 1;
    } else {
        s += k;
    }
    if (m / 60 >= 1) {
        h += m / 60;
        m -= (m / 60 * 60);
    }
    cout << h << " " << m << " " << s;
    return 0;
}
