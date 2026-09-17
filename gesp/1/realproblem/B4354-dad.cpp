#include <iostream>

int main() {
    int n,k,t;
    std::cin >> n >> k >> t;
    int pages = t * k;
    if (pages > n) {
        std::cout << n;
    } else {
        std::cout << pages;
    }
    return 0;
}