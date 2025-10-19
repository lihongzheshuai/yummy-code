#include <iostream>

int main() {
    freopen("f_reopen_demo.in", "r", stdin);
    freopen("f_reopen_demo.out", "w", stdout);
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b;
    return 0;
}