#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        bool flag = false;
        double c = sqrt(sqrt(a));
        int d = (int)c;
        if (pow(d, 4) == a) {
            flag = true;
        }
        if (flag) {
            cout << d << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
