#include <iostream>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::cout << n - (x + y - 1) / x;
    return 0;
}