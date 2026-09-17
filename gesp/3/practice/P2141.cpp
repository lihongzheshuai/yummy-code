/**
 * 题目: 【GESP】C++三级练习 luogu-P2141 [NOIP 2014 普及组] 珠心算测验
 * 题号: P2141
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p2141/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 存储输入的数组，最大长度105
int array[105] = {0};
// 标记数组，用于记录数字是否出现过，最大长度20005
int r_array[20005] = {0};
int main() {
    // 输入数组长度
    int n;
    std::cin >> n;
    // 读入数组并标记每个数字
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        // 将输入的数字在标记数组中标记为1
        r_array[array[i]] = 1;
    }
    // 计数器，记录满足条件的数字个数
    int count = 0;
    // 双重循环，遍历所有可能的数字对
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 如果两数之和在原数组中存在
            if (r_array[array[i] + array[j]]) {
                count++;
                // 将已经计数过的和标记为0，避免重复计数
                r_array[array[i] + array[j]] = 0;
            }
        }
    }
    // 输出结果
    std::cout << count;
    return 0;
}
