/**
 * 题目: 【GESP】C++二级真题 luogu-B4357 [GESP202506 二级] 幂和数
 * 题号: B4357
 * 归属: GESP2级 (202506认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4357/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>


int main() {
    // 定义输入的范围边界
    int l, r;
    // 从标准输入读取 l, r
    std::cin >> l >> r;
    // 计数器，记录幂和数的个数
    int count = 0;
    // 遍历范围内的每个数
    for (int i = l; i <= r; i++) {
        // 标记是否找到符合条件的幂和
        bool flag = false;
        // 第一个2的幂次数
        int x = 0;
        // 枚举第一个2的幂，直到超过范围上限
        while (std::pow(2, x) <= r) {
            // 第二个2的幂次数
            int y = 0;
            // 枚举第二个2的幂，直到超过范围上限
            while (std::pow(2, y) <= r) {
                // 判断当前两个2的幂之和是否等于目标数i
                if (std::pow(2, x) + std::pow(2, y) == i) {
                    flag = true;
                    count++;
                } else {
                    // 不相等时增加第二个幂次数
                    y++;
                }
                // 如果找到符合条件的组合，跳出内层循环
                if (flag) {
                    break;
                }
            }
            // 如果找到符合条件的组合，跳出外层循环
            if (flag) {
                break;
            } else {
                // 未找到时增加第一个幂次数
                x++;
            }
        }
    }
    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
