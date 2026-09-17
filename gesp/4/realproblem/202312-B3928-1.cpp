/**
 * 题目: 【GESP】C++四级真题 luogu-B3928 [GESP202312 四级] 田忌赛马
 * 题号: B3928
 * 归属: GESP4级 (202312认证真题)
 * 解法: 解法 1 / 共 2 种解法
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
    // 读取输入数据
    int n;
    std::cin >> n;
    // 读入我方马匹速度
    for (int i = 0; i < n; i++) {
        std::cin >> m_array[i];
    }
    // 读入田忌马匹速度
    for (int i = 0; i < n; i++) {
        std::cin >> t_array[i];
    }

    // 对输入数据进行排序，便于后续比较
    // 将我方马匹按速度从小到大排序
    std::sort(m_array, m_array + n);
    // 将田忌马匹按速度从小到大排序
    std::sort(t_array, t_array + n);

    // 计算满足条件的数对数量
    // count记录获胜场次
    int count = 0;
    // last_j记录上一次找到的田忌马匹位置
    int last_j = n;

    // 从后向前遍历 m_array，寻找满足条件的数对
    // 采用贪心策略，用我方最快的马去比较
    for (int i = n - 1; i >= 0; i--) {
        // 从最后一个满足条件的数开始向前遍历 t_array，找到第一个满足条件的数对
        // 寻找比我方马匹慢的田忌马匹中最快的一匹
        for (int j = last_j - 1; j >= 0; j--) {
            // 如果找到一匹比田忌的马快，就可以获胜
            if (m_array[i] > t_array[j]) {
                count++;
                // 更新最后一个满足条件的数的索引，避免重复使用
                last_j = j;
                break;
            }
        }
    }

    // 输出满足条件的数对数量，即最多获胜场次
    std::cout << count;
    return 0;
}
