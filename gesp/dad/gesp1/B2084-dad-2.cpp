#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n - 1; i++) {
        if (n % i == 0) {
            cout << n / i;
            break;
        }
    }
    return 0;
}