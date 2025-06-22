#include <iostream>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int ary[n];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> ary[j];
            sum += ary[j];
        }
        bool flag = false;
        int l_sum = 0;
        for (int j = 0; j < n; j++) {
            l_sum += ary[j];
            if (l_sum == sum - l_sum) {
                flag = true;
                break;
            }
        }

        if (flag) {
            std::cout << "Yes" << std::endl;
            flag = false;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}