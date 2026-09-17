#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b = 1;
    for (int i = a; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (b / 10 == 0) {
                printf("%.02d", b);
            } else {
                printf("%d", b);
            }
            b++;
        }
        cout << endl;
    }
    return 0;
}
