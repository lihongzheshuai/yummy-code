#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    int mid = n / 2 + 1;
    for (int i = 1; i <=n; i++) {
        int d = std::abs(mid - i);
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                if (j == mid) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            } else {
                if (j == mid + d || j == mid - d || j == mid + d || j == mid - d) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            }
        }
        std::cout << "\n";
    }
    return 0;
}