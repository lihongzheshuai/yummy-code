#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int u = 0;
    for (int i = 1; i <= n; i++) {
        if (i * i * i == n) {
            u += 1;
        } else {
            u += 0;
        }
    }
    if (u == 0) {
        cout << "No";
    } else {
        cout << "Yes";
    }
    return 0;
}
