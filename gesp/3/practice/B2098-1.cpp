/**
 * 题目: 【GESP】C++三级练习 luogu-B2098 整数去重
 * 题号: B2098
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b2098/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义一个大小为20005的整型数组，用于存储输入的数字序列
// 初始化所有元素为0
// 数组大小设置为20005是为了确保能够容纳题目要求的最大输入规模(n≤20000)
int num_array[20005] = {};
int main() {
    // 读取输入的数字个数
    int n;
    std::cin >> n;

    // 遍历输入的每个数字
    for (int i = 0; i < n; i++) {
        // 读取当前数字
        int num;
        std::cin >> num;

        // 标记当前数字是否已经出现过
        bool flag = true;

        // 检查当前数字是否在之前的数组中出现过
        for (int j = 0; j < i; j++) {
            if (num_array[j] == num) {
                // 如果找到重复数字，设置标记为false并跳出循环
                flag = false;
                break;
            }
        }

        // 如果是第一次出现的数字，则输出并保存到数组中
        if (flag) {
            std::cout << num << " ";
            num_array[i] = num;
        }
    }
    return 0;
}
