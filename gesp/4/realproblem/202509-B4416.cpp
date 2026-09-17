/**
 * 题目: 【GESP】C++四级真题 luogu-B4416 [GESP202509 四级] 最长连续段
 * 题号: B4416
 * 归属: GESP4级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4416/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 最大数据范围：1e5 + 5
const int MAX_N = 1 * 10e5 + 5;
int num_ary[MAX_N];

int main() {
    int n;
    std::cin >> n;
    // 读入原始数组
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i];
    }

    // 关键思路：排序后，相同数字会相邻，连续段只可能由“排序后相邻且差为 1”的数字组成
    std::sort(num_ary, num_ary + n);

    int max_count = 0; // 记录全局最长连续段长度
    int count = 1;     // 当前连续段长度，初始为 1（单个数字也算连续段）
    int idx = 0;       // 当前连续段的起始下标

    for (int i = idx; i < n; i++) {
        // 跳过重复数字：重复数字对“连续段”长度无贡献
        if (num_ary[i + 1] == num_ary[i]) {
            idx++;
            continue;
        }
        // 若下一个数字刚好比当前大 1，则当前连续段可以延长
        else if (num_ary[i + 1] == num_ary[i] + 1) {
            count++;
            idx++;
        }
        // 否则连续段中断，更新答案并重启计数
        else {
            max_count = std::max(max_count, count);
            count = 1;
            idx = i + 1;
        }
    }
    // 最后一次连续段可能未被更新，再取一次最大值
    max_count = std::max(max_count, count);

    std::cout << max_count << std::endl;
    return 0;
}
