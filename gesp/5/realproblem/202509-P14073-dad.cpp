#include <iostream>

// 判断一个数是否为素数
// 使用试除法，从 2 遍历到 sqrt(num)
bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;  // 如果能被整除，说明不是素数
        }
    }
    return true;  // 无法被整除，说明是素数
}

int main() {
    int n;
    std::cin >> n;

    // 特殊情况：如果 n=1，只能选 1 个数（即 1 本身）
    if (n == 1) {
        std::cout << "1" << std::endl;
        return 0;
    }

    int count = 0;
    // 贪心策略：选取 1 和所有 <= n 的素数
    // 1 和任何数互质。任意两个不同的素数互质。
    // 素数和 1 也互质。
    // 所以我们统计 2 到 n 之间的素数个数
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }

    // 最后加上 1（因为 1 也是选取的数）
    std::cout << count + 1 << std::endl;
    return 0;
}