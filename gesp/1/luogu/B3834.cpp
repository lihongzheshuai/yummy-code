#include <iostream>
using namespace std;
int main() {
    int b;
    cin >> b;
    int a = 0;
    for (int i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            a += 1;
        }
    }
    cout << a;
}
