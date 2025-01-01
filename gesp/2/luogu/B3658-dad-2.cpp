#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    double temp = (double)x / y;
    int result;
    if (temp >= 0) {
        result = (int)temp;
    } else {
        if (x % y == 0) {
            result = (int)temp;
        } else {
            result = ((int)abs(temp) + 1) * -1;
        }
    }
    cout << result;
    return 0;
}