/**
 * 题目: 【GESP】C++三级练习 luogu-B2096 直方图
 * 题号: B2096
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b2096/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

// 定义一个大小为100005的整型数组，用于统计每个数字出现的次数
// 数组大小取100005是因为题目限制了输入数字的最大值不超过100000
// 初始化所有元素为0
int count_ary[100005] = {};
int main() {
    // 读取数组大小
    int n;
    std::cin >> n;
    // 记录数组中的最大值，初始化为-1
    int max_num = -1;
    // 遍历输入的n个数字
    for (int i = 0; i < n; i++) {
        // 读取当前数字
        int cur_num;
        std::cin >> cur_num;

        // 更新最大值
        max_num = std::max(max_num, cur_num);

        // 统计当前数字出现的次数
        count_ary[cur_num]++;
    }

    // 输出从0到最大值之间每个数字出现的次数
    for (int i = 0; i <= max_num; i++) {
        std::cout << count_ary[i] << "\n";
    }
    return 0;
}
