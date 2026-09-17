#include <iostream>
using namespace std;
int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;
    h +=  k / 3600;
    int last = k % 3600;
    m += last /60;
    last = last % 60;
    s += last;
    if (s >= 60) {
        m++;
        s -= 60;
    }
    if (m >= 60) {
        h++;
        m -= 60;
    }
    cout << h << " " << m << " " << s;
    return 0;
}
