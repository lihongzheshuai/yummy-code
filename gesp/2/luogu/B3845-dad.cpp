#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                if (i * i + j * j == k * k) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}