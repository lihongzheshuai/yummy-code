#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int h = 0;
    for (int i = 1; i <= n; i++) {
        h += i;
    }
    cout << h;
    return 0;
}
