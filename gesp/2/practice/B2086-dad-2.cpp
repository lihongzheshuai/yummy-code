#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int count = 0;
    for (int i = 0; i <= 1000; i++) {
        if ((c - a * i) >= 0 && (c - a * i) % b == 0) {
            count++;
        }
    }
    cout << count;
    return 0;
}