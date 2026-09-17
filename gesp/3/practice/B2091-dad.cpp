#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ary_1[n];
    int ary_2[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary_1[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> ary_2[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ary_1[i] * ary_2[i];
    }
    std::cout << sum;
    return 0;
}