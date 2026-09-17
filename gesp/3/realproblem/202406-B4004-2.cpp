/**
 * 题目: 【GESP】C++三级真题 luogu-B4004 [GESP202406 三级] 寻找倍数
 * 题号: B4004
 * 归属: GESP3级 (202406认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4004/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    // 读取测试用例数量
    int t;
    std::cin >> t;
    while (t--) {
        // 读取序列长度
        int n;
        std::cin >> n;
        // 定义数组并找出最大值
        int ary[n];
        int max_n = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> ary[i];
            max_n = std::max(max_n, ary[i]);
        }
        // 检查最大值是否是所有数的倍数
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (max_n % ary[i] != 0) {
                flag = false;
                break;
            }
        }
        // 输出结果
        if (flag) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
