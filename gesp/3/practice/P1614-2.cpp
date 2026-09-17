/**
 * 题目: 【GESP】C++三级练习 luogu-P1614 爱与愁的心痛
 * 题号: P1614
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p1614/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>


// 定义数组存储刺痛值，大小为3005以满足数据范围要求
int array[3005];
int main() {
    // 定义n表示事件总数，m表示连续事件数
    int n, m;
    std::cin >> n >> m;

    // m_sum用于存储当前窗口的和，min_sum存储最小和
    int m_sum = 0;
    int min_sum = 0;
    // 遍历所有事件
    for (int i = 1; i <= n; i++) {
        // 读取每个事件的刺痛值
        std::cin >> array[i];
        if (i <= m) {
            // 前m个数直接累加
            m_sum += array[i];
            min_sum = m_sum;
        } else {
            // 滑动窗口：减去窗口最左边的值，加上新的值
            m_sum = m_sum - array[i - m] + array[i];
            // 更新最小和
            min_sum = std::min(min_sum, m_sum);
        }
    }
    // 输出连续m个刺痛值的最小和
    std::cout << min_sum;
    return 0;
}
