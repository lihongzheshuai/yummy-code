#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mid_idx = n;
    for (int i =1; i <= n; i++) {
        for (int j = 1; j <=  2 * n - 1; j++) {
            if (j >= mid_idx - i + 1 && j <= mid_idx + i - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}