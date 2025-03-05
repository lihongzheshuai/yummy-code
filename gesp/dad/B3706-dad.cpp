#include <cmath>
#include <iostream>

using namespace std;
int main() {
    long long x, z;
    cin >> x >> z;
    double c;
    cin >> c;
    long long y = x - 2 * z;
    cout << ceil(y / c);
    return 0;
}