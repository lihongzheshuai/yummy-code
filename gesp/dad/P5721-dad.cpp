#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int count = 1;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%02d", count);
            count++;
        }
        cout << endl;
    }

    return 0;
}
