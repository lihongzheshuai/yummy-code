/**
 * 题目: 【GESP】C++三级练习 luogu-B2098 整数去重
 * 题号: B2098
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b2098/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

// 用于存储不重复数字的向量
std::vector<int> num_array;
int main() {
    // 读取输入的数字个数
    int n;
    std::cin >> n;

    // 遍历输入的每个数字
    for (int i = 0; i < n; i++) {
        // 读取当前数字
        int num;
        std::cin >> num;

        // 标记当前数字是否为第一次出现
        bool flag = true;

        // 检查当前数字是否在向量中已经存在
        for (const int& v : num_array) {
            if (v == num) {
                // 如果找到重复数字，设置标记为false并跳出循环
                flag = false;
                break;
            }
        }

        // 如果是第一次出现的数字，则输出并添加到向量中
        if (flag) {
            std::cout << num << " ";
            num_array.push_back(num);
        }
    }
    return 0;
}
