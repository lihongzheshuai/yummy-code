#include <iostream>

int main() {
    int x;
    std::cin >> x;
    bool flag = false;
    int y = 0;
    while (y <= 2025) {
        if ((x & y) + (x | y) == 2025) {
            flag = true;
            break;
        }
        y++;
    }
    if (flag) {
        std::cout << y;
    } else {
        std::cout << "-1";
    }
    return 0;
}