#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    int max = 0;
    for (int i = 0; i < b; i++) {
        if (a != 6 && a != 7) {
            max += 250;
        }
        if (a >= 7) {
            a = 1;
        } else {
            a += 1;
        }
    }
    cout << max;
    return 0;
}
