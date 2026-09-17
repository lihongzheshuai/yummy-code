#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 1;
    int y = (n + 1) / 2;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        for (int j = 1; j <= y - 1; j++) {
            cout << " ";
        }
        for (int k = 1; k <= ans; k++) {
            cout << "*";
        }
        for (int p = 1; p <= y - 1; p++) {
            cout << " ";
        }
        y--;
        ans += 2;
        cout << endl;
    }
    y = 1;
    ans = n - 2;
    for (int i = 1; i <= (n + 1) / 2 - 1; i++) {
        for (int j = 1; j <= y; j++) {
            cout << " ";
        }
        for (int k = 1; k <= ans; k++) {
            cout << "*";
        }
        for (int p = 1; p <= y; p++) {
            cout << " ";
        }
        y += 1;
        ans -= 2;
        cout << endl;
    }
    return 0;
}
