#include <iostream>
using namespace std;
int main() {
    int year, month;
    cin >> year >> month;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
        cout << 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        cout << 30;
    } else if (month == 2) {
        if (!((a % 4 == 0 && a % 100 != 0) || a % 400 != 0)) {
            cout << 28;
        } else {
            cout << 29;
        }
    }
    return 0;
}
