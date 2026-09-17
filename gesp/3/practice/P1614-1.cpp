/**
 * 题目: 【GESP】C++三级练习 luogu-P1614 爱与愁的心痛
 * 题号: P1614
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p1614/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

// 定义数组存储每个事件的刺痛值
int array[3005];
int main() {
    // 定义变量n表示事件总数，m表示连续事件数
    int n, m;
    // 从标准输入读取n和m
    std::cin >> n >> m;
    // 读取每个事件的刺痛值
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    // 初始化最小和为一个较大的值
    int min_sum = 30000000;
    // 遍历所有可能的连续m个事件的组合
    for (int i = 0; i <= n - m; i++) {
        // 计算当前连续m个事件的刺痛值之和
        int cur_sum = 0;
        for (int j = i; j < i + m; j++) {
            cur_sum += array[j];
        }
        // 更新最小和
        min_sum = std::min(min_sum,cur_sum);
    }
    // 输出连续m个刺痛值的最小和
    std::cout << min_sum;
    return 0;
}
