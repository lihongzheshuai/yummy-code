#include <iostream>
#include <vector>

// nums 数组用于标记数是否为合数（非素数）
// 0 表示可能是素数（初始状态），1 表示是合数
int nums[100005];

int main() {
    int n;
    std::cin >> n;
    std::vector<int> primes;  // 存储找到的素数

    // 使用埃氏筛法 (Sieve of Eratosthenes) 找出 2 到 n 的所有素数
    for (int i = 2; i <= n; i++) {
        // 如果 nums[i] 为 0，说明 i 是素数
        if (nums[i] == 0) {
            primes.push_back(i);
            // 将 i 的倍数标记为合数
            // 从 i 开始，每次增加 i (i, 2i, 3i...)
            // 注意：这里从 i 开始标记，虽然 i 本身是素数，但标记为 1
            // 后不影响后续判断（因为 i 已经处理过了）
            for (int j = i; j <= n; j += i) {
                nums[j] = 1;
            }
        }
    }

    // 贪心策略：选取 1 和所有素数
    // 输出素数个数 + 1 (这个 1 代表数字 1)
    std::cout << primes.size() + 1 << std::endl;
    return 0;
}