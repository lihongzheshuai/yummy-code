#include <cmath>
#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;
    int ary[n];
    int min_n = 100001;
    int max_n = -100001;
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
        min_n = std::min(min_n, ary[i]);
        max_n = std::max(max_n, ary[i]);
    }

    for (int i = 0; i < n; i++) {
        if (ary[i] > k) {
            ary[i] = max_n;
        } else if (ary[i] < k) {
            ary[i] = min_n;
        }
        std::cout << ary[i] << " ";
    }
    return 0;
}