#include <iostream>
#include <cmath>

int nums[15];

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    long long l = std::max(a, b);
    long long s = std::min(a, b);
    return l * s / gcd(l, s);
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    long long result = nums[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, nums[i]);
    }
    std::cout << result << std::endl;
    return 0;
}