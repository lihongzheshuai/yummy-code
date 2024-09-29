#include <iostream>
using namespace std;
int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << n - ((a - c) + (b - c) + c);
    return 0;
}
