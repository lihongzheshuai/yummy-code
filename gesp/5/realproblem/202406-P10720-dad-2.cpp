#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        int count = 0;
        for (int j = 2; j <= sqrt(a); j++) {
            if (a % j == 0) {
                count++;
            }
            while (a % j == 0) {
                a /= j;
            }
            if (count > 2) {
                break;
            }
        }
        if (a > 1) {
            count++;
        }
        std::cout << (count == 2 ? 1 : 0) << std::endl;
    }

    return 0;
}