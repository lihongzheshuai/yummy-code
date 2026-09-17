#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k = 1;
    int x = 100;
    while(true) {
        double tmp_k = (n / 52 - 7 * x) /  21.0;
        if (tmp_k < 1) {
            x--;
            continue;
        }
        k = (int) tmp_k;
        if (k == tmp_k) {
            cout << x << endl << k;
            break;
        } else {
            x--;
            continue;
        }
    }
    return 0;
}