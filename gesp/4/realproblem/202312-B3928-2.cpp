/**
 * 题目: 【GESP】C++四级真题 luogu-B3928 [GESP202312 四级] 田忌赛马
 * 题号: B3928
 * 归属: GESP4级 (202312认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3928/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 定义最大数组长度，题目要求N最大为5*10^4
const int max_n = 5 * 10e4 + 5;
// t_array存储田忌的马匹速度
int t_array[max_n];
// m_array存储我方马匹速度
int m_array[max_n];

int main() {
    // 读取马匹数量N
    int n;
    std::cin >> n;

    // 读取我方马匹速度数组
    for (int i = 0; i < n; i++) {
        std::cin >> m_array[i];
    }

    // 读取田忌马匹速度数组
    for (int i = 0; i < n; i++) {
        std::cin >> t_array[i];
    }

    // 对两方马匹速度进行排序，便于采用贪心策略
    std::sort(m_array, m_array + n);
    std::sort(t_array, t_array + n);

    // count记录获胜场次
    int count = 0;

    // 采用贪心策略，从最慢的马开始比较
    // i遍历我方马匹，j遍历田忌马匹
    // 如果我方当前马匹比田忌当前马匹快，就可以获胜一场
    for (int i = 0, j = 0; i < n; i++) {
        // 如果我方当前马比田忌当前马快，就可以获胜
        if (m_array[i] > t_array[j]) {
            // 获胜场次加1
            count++;
            // 田忌下一匹马
            j++;
        }
        // 如果我方马不够快，就跳过这轮，用下一匹更快的马去比
    }

    // 输出最多获胜场次
    std::cout << count;
    return 0;
}
