#include <iostream>
#include <cmath>

int main() {
    int l,r;
    std::cin >> l >> r;
    int count = 0;
    for (int i = 0; i<=31; i++) {
        for (int j = i; j<=31; j++) {
            int num = std::pow(2,i) + std::pow(2,j);
            if (num >= l && num <= r) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}