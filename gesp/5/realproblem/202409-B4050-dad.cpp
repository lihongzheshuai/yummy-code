#include <cmath>
#include <iostream>

int is_equal_sum(int target) {
    int tmp_sum = 0;
    for (int j = 0; j < 31; j++) {
        tmp_sum += std::pow(2, j);
        if (tmp_sum == target) {
            return j + 1;
        }
        if (tmp_sum > target) {
            return -1;
        }
    }
    return -1;
}

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    std::cin >> t;


    for (int i = 0; i < t; i++) {
        int h;
        std::cin >> h;
        int count = is_equal_sum(h);
        
        for (int j = h; j >= 2; j--) {
            if (is_prime(j)) {
                int target = h - j;
                if (target == 0) {
                    count = 1;
                    break;
                }
                int tmp_count = is_equal_sum(target);
                if (tmp_count != -1) {
                    if (count == -1) {
                        count = tmp_count + 1;
                    } else {
                        count = std::min(count, tmp_count + 1);
                    }
                    break;
                }
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
