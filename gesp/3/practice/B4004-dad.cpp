#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int ary[n];
        for (int j = 0; j < n; j++) {
            std::cin >> ary[j];
        }
        bool flag = false;
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int k = 0; k < n; k++) {
                if (ary[j] % ary[k] == 0) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == n) {
                std::cout << "Yes" << std::endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}