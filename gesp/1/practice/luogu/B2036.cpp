#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    double a;
    cin >> a;
    if (a >= 0) {
        printf("%.2f", a);
    } else {
        printf("%.2f", a * -1);
    }
    return 0;
}
