#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mid_idx = (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == mid_idx && j == mid_idx) {
                cout << "*";

            } else if (i < mid_idx) {
                if (j == mid_idx - i + 1 || j == mid_idx + i - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            } else {
                if (j == i -mid_idx + 1 || j == n - i + mid_idx) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}