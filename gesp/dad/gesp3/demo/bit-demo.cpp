#include <iostream>

int main() {
    std::cout << (0 & 1) << std::endl;
    std::cout << (0 | 1) << std::endl;
    int list[10] = {0};
    std::cout << list << std::endl;
    double list2[10] = {0};
    std::cout << list2 << std::endl;
    char cary[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::cout << cary << std::endl;
    return 0;
}