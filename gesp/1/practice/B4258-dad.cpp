#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int x;
        std::cin >> x;
        int last_num = x % 10;
        if (last_num < 5) {
            std::cout << x - last_num << std::endl;
        } else {
            std::cout << x + (10 - last_num) << std::endl;
        }
    }
    return 0;
}