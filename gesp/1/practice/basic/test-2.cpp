#include <iostream>
using namespace std;
int main() {
    int _a;
    // cin >> _a;
    int sum = 1;
    for (int i = 1; i <= 10; i++) {
        if (3 <= i <= 5) {
			sum += i;
        }
    }
	cout << "sum = " << sum;
    // while (_a == 1) {
    //     cout << 1 << " ";
    // }
    // do {
    //     cout << 1 << " ";
    // } while (_a == 1);
    // cout << _a;
    return 0;
}
