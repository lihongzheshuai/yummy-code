#include <iostream>

int nums[1000005];

bool is_prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n, B;
    std::cin >> n >> B;

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (i <= B && is_prime(i)) {
            for (int j = i; j <= n; j += i) {
                if (nums[j] == 0) {
                    // std::cout << "i: " << i << " j: " << j << std::endl;
                    nums[j] = 1;
                    count++;
                }
            }
        }
        if (i > B && is_prime(i)) {
            for (int j = i; j <= n; j += i) {
                if (nums[j] == 1) {
                    // std::cout << "i: " << i << " j: " << j << std::endl;
                    nums[j] = 0;
                    count--;
                }
            }
        }
    }
    std::cout << count + 1 << std::endl;
    return 0;
}