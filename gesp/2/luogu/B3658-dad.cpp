#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    double temp_float = (double) x / y;
    cout << floor(temp_float) ;
    return 0;
}