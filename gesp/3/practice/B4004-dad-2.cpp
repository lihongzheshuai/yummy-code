#include <cmath>
#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int ary[n];
        int max_n = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> ary[i];
            max_n = std::max(max_n, ary[i]);
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (max_n % ary[i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}