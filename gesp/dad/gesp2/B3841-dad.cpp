#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int copy_m = m;
        int pows = 0;
        while (copy_m != 0) {
            copy_m /= 10;
            pows++;
        }
        int sum = 0;
        copy_m = m;
        while (copy_m != 0) {
            sum += pow(copy_m % 10, pows);
            copy_m /= 10;
        }
        if (sum == m) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }
    return 0;
}
