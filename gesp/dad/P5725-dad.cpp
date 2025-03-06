#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%02d", i * n + j);
        }
        cout << endl;
    }
    cout << endl;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < n - i) {
                cout << "  ";
            } else {
                printf("%02d", cur);
                cur++;
            }
        }
        cout << endl;
    }
    return 0;
}