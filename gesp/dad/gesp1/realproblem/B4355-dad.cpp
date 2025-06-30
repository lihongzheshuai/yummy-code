#include <iostream>

int main() {
    int n,m;
    std::cin >> n >> m;
    int big = n > m ? n : m;
    for (int i = big; ;i++) {
        if (i % n == 0 && i % m == 0) {
            std::cout << i;
            break;
        }
    }
    return 0;
}
