/**
 * 题目: 【GESP】C++五级练习题（前缀和） luogu-P1114 “非常男女”计划
 * 题号: P1114
 * 归属: GESP5级
 * 博客: https://www.coderli.com/gesp-5-luogu-p1114/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
#include <algorithm>

// current_sum 数组：存储到当前位置 i 为止的前缀和。
// 这里的 i 是从 1 到 n，所以大小为 n+1。
// n 最大 10^5，所以 100005 足够。
int current_sum[100005];

// first_pos 数组：用于记录某个“前缀和”数值第一次出现的下标位置。
// 因为前缀和可能为负数，范围在 -n 到 +n 之间。
// n 最大 10^5，所以范围是 [-100000, 100000]，总共 200001 种可能的值。
// 数组大小 200005 足够覆盖这个范围，并通过偏移量映射到非负下标。
int first_pos[200005];

// 定义偏移量 OFFSET
// 作用：将负数前缀和映射到数组的非负下标。
// 例如，如果前缀和为 -5，在数组中访问 first_pos[-5 + OFFSET]。
const int OFFSET = 100000;

int main() {
    // n：表示学校的人数
    int n;
    // 从标准输入读取人数 n
    std::cin >> n;

    // 循环读取 n 个学生的性别 (0 或 1)，并计算前缀和
    // i 从 1 开始，与题目描述的序列下标习惯一致
    for (int i = 1; i <= n; i++) {
        int num; // 用于存储当前学生的性别 (0 或 1)
        std::cin >> num; // 读取当前学生的性别

        // 核心转化：将 0 (女生) 视为 -1，将 1 (男生) 视为 +1。
        // 这样“男女人数相等”就等价于“区间和为 0”。
        if (num == 0) {
            num = -1;
        }
        // 计算到当前位置 i 的前缀和
        // current_sum[i] = current_sum[i-1] + (当前学生的转化值)
        current_sum[i] = current_sum[i - 1] + num;
    }

    int max_len = 0; // 初始化最长平衡子区间的长度为 0

    // 初始化 first_pos 数组：将所有位置填充为 -1。
    // -1 表示该前缀和数值尚未出现过。
    std::fill(first_pos, first_pos + 200005, -1);

    // 初始状态设置：
    // 还没开始读入数据时 (即在第 0 个位置之前)，前缀和为 0。
    // 这很重要：如果后续某个位置 i 的前缀和 current_sum[i] 再次变为 0，
    // 那么从序列的开始到位置 i 的这段区间 (长度为 i) 就是一个平衡区间。
    // first_pos[0 + OFFSET] 存储的是前缀和为 0 第一次出现的下标，即 0。
    first_pos[0 + OFFSET] = 0;

    // 再次循环遍历计算出的前缀和数组 (从第一个学生开始)
    for (int i = 1; i <= n; i++) {
        // 计算在 first_pos 数组中的实际索引（加上偏移量，转为非负数）
        int index = current_sum[i] + OFFSET;

        // 检查这个前缀和是否之前出现过
        if (first_pos[index] == -1) {
            // 情况 B：如果这个前缀和是第一次出现
            // 记录当前的下标 i。
            first_pos[index] = i;
        } else {
            // 情况 A：这个前缀和之前出现过！
            // 计算当前平衡子区间的长度：当前下标 i - 第一次出现的下标 first_pos[index]
            // 并用 std::max 更新最长长度
            max_len = std::max(max_len, i - first_pos[index]);
        }
    }

    // 输出最终找到的最长平衡子区间的长度
    std::cout << max_len << std::endl;
    return 0;
}
