#include <iostream>
#include <cmath>

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::cout << n - std::ceil((double)y / x);
    return 0;
}