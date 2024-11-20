#include <iostream>
using namespace std;
int main() {
    int x;
    cin >> x;
    if (x % 3 == 0 && x % 5 == 0 && x % 7 == 0) {
        cout << "3 5 7";
    } else if ((x % 3 == 0 && x % 5 == 0) && x % 7 != 0) {
        cout << "3 5";
    } else if ((x % 3 == 0 && x % 7 == 0) && x % 5 != 0) {
        cout << "3 7";
    } else if ((x % 5 == 0 && x % 7 == 0) && x % 3 != 0) {
        cout << "5 7";
    } else if ((x % 3 == 0 && x % 5 == 0) && x % 7 != 0) {
        cout << "3";
    } else if ((x % 3 != 0 && x % 5 == 0) && x % 7 != 0) {
        cout << "5";
    } else if ((x % 3 != 0 && x % 5 != 0) && x % 7 == 0) {
        cout << "7";
    } else {
        cout << "n";
    }
    return 0;
}
