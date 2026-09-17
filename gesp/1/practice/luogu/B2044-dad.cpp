#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    if (a < 60) {
        count++;
    }
    if (b < 60) {
        count++;
    }
    if (c < 60) {
        count++;
    }
    if (count == 1) {
        cout << 1;
    } else {
        cout << 0;
    }
    return 0;
}
