#include <cmath>
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sqr_i = std::sqrt(ary[i] + ary[j]);
            if (sqr_i * sqr_i == ary[i] + ary[j]) {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}