/**
 * 题目: 【GESP】C++三级真题 luogu-B4066 [GESP202412 三级] 数字替换
 * 题号: B4066
 * 归属: GESP3级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4066/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    // 声明变量n和k，分别表示序列长度和比较基准值
    int n, k;
    std::cin >> n >> k;

    // 声明数组ary存储序列，并初始化最大值最小值变量
    int ary[n];
    int min_n = 100001;    // 初始化为一个较大的值
    int max_n = -100001;   // 初始化为一个较小的值

    // 读入序列并同时找出最大值和最小值
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
        min_n = std::min(min_n, ary[i]);  // 更新最小值
        max_n = std::max(max_n, ary[i]);  // 更新最大值
    }

    // 遍历序列进行替换并输出
    for (int i = 0; i < n; i++) {
        if (ary[i] > k) {
            ary[i] = max_n;     // 大于k的数替换为最大值
        } else if (ary[i] < k) {
            ary[i] = min_n;     // 小于k的数替换为最小值
        }
        std::cout << ary[i] << " ";  // 输出处理后的数
    }
    return 0;
}
