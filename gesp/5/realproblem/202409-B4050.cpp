/**
 * 题目: 【GESP】C++五级真题（数论-素数、贪心思想考点） luogu-B4050 [GESP202409 五级] 挑战怪物
 * 题号: B4050
 * 归属: GESP5级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-b4050/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

// 判断 target 能否被“纯物理攻击”恰好耗尽
// 物理攻击第 i 次伤害为 2^(i-1)，累加和为 2^i - 1
// 返回所需攻击次数；若无法恰好耗尽则返回 -1
int is_equal_sum(int target) {
    int tmp_sum = 0;
    for (int j = 0; j < 31; j++) {
        tmp_sum += std::pow(2, j);   // 累加 2^0 + 2^1 + ... + 2^j
        if (tmp_sum == target) {
            return j + 1;            // 恰好耗尽，返回攻击次数
        }
        if (tmp_sum > target) {
            return -1;               // 已超过，后续更大，直接失败
        }
    }
    return -1;                       // 31 次内仍无法满足
}

// 朴素判断 n 是否为质数
bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= std::sqrt(n); i++) {
        if (n % i == 0) {
            return false;            // 出现因子，非质数
        }
    }
    return true;                       // 无因子，质数
}

int main() {
    int t;
    std::cin >> t;                     // 读入测试组数

    for (int i = 0; i < t; i++) {
        int h;
        std::cin >> h;                 // 当前怪物血量

        // 先尝试“纯物理攻击”能否恰好击败
        int count = is_equal_sum(h);

        // 再尝试“使用一次魔法攻击”的情况：枚举魔法伤害质数 x
        // 从大到小枚举，可更快找到最小总次数（贪心思想）
        for (int j = h; j >= 2; j--) {
            if (is_prime(j)) {         // j 是质数，可作为魔法伤害
                int target = h - j;    // 剩余需用物理攻击补足的血量
                if (target == 0) {
                    count = 1;         // 仅一次魔法攻击即可
                    break;
                }
                int tmp_count = is_equal_sum(target);
                if (tmp_count != -1) { // 剩余血量可被物理攻击恰好耗尽
                    int total = tmp_count + 1; // 总次数 = 物理次数 + 1 次魔法
                    if (count == -1 || total < count) {
                        count = total; // 更新最小次数
                    }
                    // 由于从大到小枚举，首次合法即最优，可提前退出
                    break;
                }
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
