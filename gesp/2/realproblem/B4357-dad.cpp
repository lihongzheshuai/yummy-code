#include <cmath>
#include <iostream>


int main() {
    int l, r;
    std::cin >> l >> r;
    int count = 0;
    for (int i = l; i <= r; i++) {
        bool flag = false;
        int x = 0;
        while (std::pow(2, x) <= r) {
            int y = 0;
            while (std::pow(2, y) <= r) {
                if (std::pow(2, x) + std::pow(2, y) == i) {
                    flag = true;
                    count++;
                } else {
                    y++;
                }
                if (flag) {
                    break;
                }
            }
            if (flag) {
                break;
            } else {
                x++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}