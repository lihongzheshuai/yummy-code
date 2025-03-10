#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int a;
    int count = 100000;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        count = min(a, count);
    }
    cout << count;
    return 0;
}
