#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = false;
    }
    for (int i = 1; i < n; i += 2) {
        arr[i] = true;
    }

    for (int i = 3; i <= n; i++) {
        for (int j = i - 1; j < n; j += i) {
            arr[j] = !arr[j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            cout << i + 1 << " ";
        }
    }
    return 0;
}