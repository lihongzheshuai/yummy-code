#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int mid = n / 2 + 1;
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n) {
                if (j == mid) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            } else if (i < mid) {
                if (j == mid - i + 1 || j == mid + i - 1) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            } else {
                if (j == i - mid + 1 || j == n - i + mid) {
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