#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = n; i >= 1; i--) {
        if (i % k == 0) {
            cout << i;
            break;
        }
    }
    return 0;
}
