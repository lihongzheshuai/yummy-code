#include <iostream>
#include <algorithm>

const int max_n = 5 * 10e4 + 5;
int t_array[max_n];
int m_array[max_n];

int main() {
    // 读取输入数据
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m_array[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> t_array[i];
    }

    // 对输入数据进行排序
    std::sort(m_array, m_array + n);
    std::sort(t_array, t_array + n);

    // 计算满足条件的数对数量
    int count = 0;
    int last_j = n;

    // 从后向前遍历 m_array，寻找满足条件的数对
    for (int i = n - 1; i >= 0; i--) {
        // 从最后一个满足条件的数开始向前遍历 t_array，找到第一个满足条件的数对
        for (int j = last_j - 1; j >= 0; j--) {
            if (m_array[i] > t_array[j]) {
                count++;
                // 更新最后一个满足条件的数的索引
                last_j = j;
                break;
            }
        }
    }

    // 输出满足条件的数对数量
    std::cout << count;
    return 0;
}