#include <iostream>
#include <vector>

// nums 数组用于标记数是否为合数
// 0 表示是素数，1 表示是合数
int nums[100005];

int main() {
    int n;
    std::cin >> n;
    std::vector<int> primes;  // 存储找到的素数

    // 使用欧拉筛（线性筛）找出 2 到 n 的所有素数
    for (int i = 2; i <= n; i++) {
        // 如果 nums[i] 未被标记，说明 i 是素数
        if (nums[i] == 0) {
            primes.push_back(i);
        }
        // 遍历已找到的素数，标记 i * p 为合数
        for (int p : primes) {
            // 如果乘积超过 n，停止标记
            if (p * i > n) {
                break;
            }
            nums[p * i] = 1;  // 标记 p * i 为合数

            // 关键点：如果 i 能被 p 整除，说明 i = k * p
            // 那么下一个要标记的数是 i * (下一个素数 p') = k * p * p'
            // 这个数会在 i' = k * p' 时被 p 标记，所以这里可以 break
            // 保证每个合数只被其最小质因子筛去，达到线性时间复杂度
            if (i % p == 0) {
                break;
            }
        }
    }

    // 贪心策略：选取 1 和所有素数
    // 输出素数个数 + 1 (这个 1 代表数字 1)
    std::cout << primes.size() + 1 << std::endl;
    return 0;
}