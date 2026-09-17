#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    double n;
    // zongjuli
    double sum = 0;
    // shanyibu
    double last = 0;
    // dangqianbu
    double current = 0;
    // mubiao juli
    scanf("%lf", &n);
    // bushu
    int count = 0;
    while (true) {
        count++;
        if (count == 1) {
            current = 2.0;
            sum += current;
            last = current;
        } else {
            current = last * 0.98;
            sum += current;
            last = current;
        }
        if (sum >= n) {
            break;
        }
    }
    printf("%d", count);
    return 0;
}
