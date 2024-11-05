#include <iostream>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a * 3600 + b * 60 + c;
    int i = n + d;
    cout << i / 3600 << " " << i % 3600 / 60 << " " << i % 3600 % 60;
    return 0;
}
