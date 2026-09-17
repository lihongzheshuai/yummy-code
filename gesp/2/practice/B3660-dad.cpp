#include <iostream>
using namespace std;
int main() {
    int times;
    cin >> times;
    for (int i = 0; i < times; i++) {
        int count;
        cin >> count;
        bool flag = false;
        for (int j = 0; j < count; j++) {
            int n;
            cin >> n;
            if (n == 0) {
                flag = true;
            }
        }
        if (flag) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}