#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int k = 0;
    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a % 8 != 0 && a % 9 == 0) {
            k += 1;
        }
    }
    cout << k;
    return 0;
}
