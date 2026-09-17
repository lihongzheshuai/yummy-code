/**
 * 题目: 【GESP】C++五级练习 luogu-P1678 烦恼的高考志愿
 * 题号: P1678
 * 归属: GESP5级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1678/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm> // 包含 std::sort 与 std::lower_bound
#include <cmath>     // 包含 std::abs 用于计算绝对值差
#include <iostream>  // 包含 std::cin 与 std::cout 输入输出
#include <vector>    // 包含 std::vector 动态数组

using namespace std;

int main() {
    // 关闭 cin/cout 与 C 标准输入输出的同步，解除 cin 与 cout 的绑定
    // 在处理 N, M 可达 10^5 的大量数据输入输出时，显著提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    // 读取学校数量 m 与学生数量 n
    if (!(cin >> m >> n)) return 0;

    // 创建大小为 m 的数组，保存 m 所学校的预计分数线
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    // 1. 对学校预计分数线进行升序排序
    // 二分查找的前提条件必须是序列具有单调性（有序）
    sort(a.begin(), a.end());

    // 2. 累计所有学生的不满意度
    // 注意：所有学生不满意度的最大可能总和为 10^5 * 10^6 = 10^11，
    // 超过了 32 位 int 的最大值 (~2.14 * 10^9)，因此必须使用 64 位 long long
    long long total_dissatisfaction = 0;

    // 3. 逐个读入每位学生的估分并进行二分查找
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b; // 读取第 i 位学生的估分

        // std::lower_bound 用于在升序区间 [a.begin(), a.end()) 内
        // 查找第一个大于等于估分 b 的学校分数线迭代器
        auto it = lower_bound(a.begin(), a.end(), b);
        // 通过 std::distance 计算该迭代器在 vector 中的下标位置 [0, m]
        int pos = distance(a.begin(), it);

        if (pos == 0) {
            // 情况一：学生估分 b 比所有学校的分数线都低
            // 最近的学校只能是最低录取线 a[0]，注意不能访问 a[-1]
            total_dissatisfaction += abs(a[0] - b);
        } else if (pos == m) {
            // 情况二：学生估分 b 比所有学校的分数线都高
            // lower_bound 返回 a.end()，下标 pos 为 m
            // 最近的学校只能是最高录取线 a[m - 1]
            total_dissatisfaction += abs(a[m - 1] - b);
        } else {
            // 情况三：学生估分 b 介于 a[pos-1] 与 a[pos] 之间
            // 离 b 最近的分数线必在小于等于 b 的最大值 a[pos-1]
            // 和大于等于 b 的最小值 a[pos] 之中产生
            int diff1 = abs(a[pos] - b);     // 计算与右侧大于等于 b 的学校的绝对差
            int diff2 = abs(a[pos - 1] - b); // 计算与左侧小于 b 的学校的绝对差
            total_dissatisfaction += min(diff1, diff2); // 取两者中的较小差值
        }
    }

    // 4. 输出所有学生最小不满意度的总和
    cout << total_dissatisfaction << "\n";

    return 0;
}
