#include <iostream>
using namespace std;
int main() {
    int p, x, y, g, h;
    cin >> p >> x >> y >> g >> h;
    if (p == 1) {
        if (x == g || y == h) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else if (p == 2) {
        cout << "No";
    } else if (p == 3) {
        if ((g == x + 2 && h == y + 1) || (g == x + 2 && h == y - 2) ||
            (g == x - 2 && h == y + 1) || (g == x - 2 && h == y - 1) ||
            (g == x + 1 && h == y + 2) || (g == x + 1 && h == y - 2) ||
            (g == x - 1 && h == y + 2) || (g == x - 1 && h == y - 2)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    } else {
        if ((g == x + 2 && h == y + 2) || (g == x + 2 && h == y - 2) ||
            (g == x - 2 && h == y + 2) || (g == x - 2 && h == y - 2)) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }
    return 0;
}
