#include <iostream>
using namespace std;
int main() {
    long long y, t;
    cin >> y >> t;
    if (t == 0) {
        cout << "NO" << endl;
        cout << "YES";
    } else {
        if (t % 2 == 0) {
            cout << "NO" << endl;
            if (y % 2 == 0) {
                cout << "NO";
            } else {
                cout << "YES";
            }
        } else {
            if (y < 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            if (y % 2 == 0) {
                cout << "NO";
            } else {
                cout << "YES";
            }
        }
    }
    return 0;
}