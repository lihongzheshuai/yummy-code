/**
 * 题目: 【GESP】C++三级真题 luogu-B4004 [GESP202406 三级] 寻找倍数
 * 题号: B4004
 * 归属: GESP3级 (202406认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4004/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取测试用例数量
    int t;
    std::cin >> t;
    // 处理每组测试用例
    for (int i = 0; i < t; i++) {
        // 读取序列长度
        int n;
        std::cin >> n;
        // 读取序列数据
        int ary[n];
        for (int j = 0; j < n; j++) {
            std::cin >> ary[j];
        }
        // 标记是否找到符合条件的数
        bool flag = false;
        // 遍历每个数，检查是否是其他所有数的倍数
        for (int j = 0; j < n; j++) {
            // 计数器，记录当前数是多少个数的倍数
            int count = 0;
            // 检查当前数是否是其他每个数的倍数
            for (int k = 0; k < n; k++) {
                if (ary[j] % ary[k] == 0) {
                    count++;
                } else {
                    // 如果不是某个数的倍数，直接跳出内层循环
                    break;
                }
            }
            // 如果当前数是所有数的倍数
            if (count == n) {
                std::cout << "Yes" << std::endl;
                flag = true;
                break;
            }
        }
        // 如果没有找到符合条件的数
        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
