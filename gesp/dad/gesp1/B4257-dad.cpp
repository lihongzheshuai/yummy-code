#include <iostream>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    if (y % x == 0) {
        std::cout << n - y / x;
    } else {
        std::cout << n - y / x - 1;
    }
    return 0;
}