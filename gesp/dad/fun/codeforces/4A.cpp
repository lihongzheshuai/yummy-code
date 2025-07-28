#include <iostream>

int main() {

    int n;
    std::cin >> n;
    if (n % 2 != 0 || n == 2) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }
    return 0;
}