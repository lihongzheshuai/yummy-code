#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int c = sqrt(i * i + j * j);
            if (c * c == j * j + i * i && c <= n) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}