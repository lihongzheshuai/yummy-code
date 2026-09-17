/**
 * 题目: 【GESP】C++五级真题（数论-素数思想考点） luogu-P10720 [GESP202406 五级] 小杨的幸运数字
 * 题号: P10720
 * 归属: GESP5级 (202406认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p10720/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

// 标记数组：is_primes[i]==0 表示 i 是质数；==1 表示合数
int is_primes[1000005];
// 线性筛得到的质数表，后续用于试除
std::vector<int> prime_nums;

int main() {
    int n;
    std::cin >> n;
    // 0 和 1 不是质数，先标记
    is_primes[0] = is_primes[1] = 1;

    // 线性筛（欧拉筛）预处理 1~1e6 的质数
    for (int i = 2; i <= 1000000; i++) {
        if (is_primes[i] == 0) {          // i 是质数，加入质数表
            prime_nums.push_back(i);
        }
        // 用当前质数表筛掉合数
        for (int num : prime_nums) {
            long long x = 1LL * i * num;    // 计算合数
            if (x > 1000000) {
                break;                      // 超出范围，退出
            }
            is_primes[x] = 1;               // 标记为合数
            if (i % num == 0) {
                break;                      // 保证每个合数只被最小质因子筛一次
            }
        }
    }

    // 处理每个询问
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        int count = 0;                      // 记录不同质因子个数
        // 用质数表试除，统计不同质因子
        for (int j = 0; j < prime_nums.size(); j++) {
            if (a % prime_nums[j] == 0) {   // 发现质因子
                count++;
            }
            if (count > 2) {                // 提前剪枝
                break;
            }
        }
        // 恰好两种质因子输出 1，否则 0
        std::cout << (count == 2 ? 1 : 0) << std::endl;
    }

    return 0;
}
}
