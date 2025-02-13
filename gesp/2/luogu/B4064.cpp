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
        if ((int)c * (int)c * (int)c * (int)c == a) {
            flag = true;
        }
        if (flag == true) {
            cout << (int)c << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
