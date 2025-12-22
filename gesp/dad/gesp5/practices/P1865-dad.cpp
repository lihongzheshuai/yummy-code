#include <iostream>
#include <vector>

// 标记数组：prime_ary[i] 为 1 表示 i 是质数，为 0 表示 i 是合数
int prime_ary[1000005];
// 前缀和数组：prime_pre[i] 表示 [1, i] 区间内质数的个数
int prime_pre[1000005];

int main() {
    int n, m;
    // 输入询问次数 n 和最大范围 m
    std::cin >> n >> m;
    std::vector<int> primes;  // 用于存储筛选出的质数

    // 初始化：假设 2 到 m 之间的数都是质数
    std::fill(prime_ary + 2, prime_ary + m + 1, 1);

    // 线性筛（欧拉筛）算法筛选质数
    for (int i = 2; i <= m; i++) {
        if (prime_ary[i] == 1) {
            primes.push_back(i);  // i 是质数，加入列表
        }
        // 遍历已有质数，标记合数
        for (int p : primes) {
            if (p * i > m) {
                break;  // 如果超出最大范围 m，停止这一轮标记
            }
            prime_ary[p * i] = 0;  // 标记 p * i 为合数
            if (i % p == 0) {
                break;  // 关键：保证每个合数只被其最小质因子筛去，保证线性时间复杂度
            }
        }
    }

    // 计算质数个数的前缀和
    for (int i = 1; i <= m; i++) {
        prime_pre[i] = prime_pre[i - 1] + prime_ary[i];
    }

    // 处理 n 次询问
    for (int i = 0; i < n; i++) {
        int l, r;
        std::cin >> l >> r;
        // 判断查询区间是否超出有效范围 [1, m]
        if (r > m || l < 1) {
            std::cout << "Crossing the line" << "\n";
            continue;
        }
        // 利用前缀和计算区间 [l, r] 内的质数个数
        std::cout << prime_pre[r] - prime_pre[l - 1] << "\n";
    }

    return 0;
}