#include <iostream>
using namespace std;
int result[101];
int a[101];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                result[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
