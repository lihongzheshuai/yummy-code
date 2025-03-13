#include<iostream>
using namespace std;
int main() {
    long long x;
    cin >> x;
    char a, b;
    cin >> a >> b;
    long long price;
    if ((a == 'B' || b == 'B') && (a == 'C' || b == 'C')) {
        price = x / 10 * 6;
    } else if ((a == 'C' || b == 'C')) {
        price = x / 10 * 7;
    } else if ((a == 'B' || b == 'B')){
        price = x / 10 * 8;
    } else {
        price = x;
    }
    cout << price;
    return 0;
}