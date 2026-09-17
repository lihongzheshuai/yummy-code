/**
 * 题目: 【GESP】C++三级练习 luogu-P1047 [NOIP 2005 普及组] 校门外的树
 * 题号: P1047
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1047/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <array>

// 定义一个长度为10005的数组，用于标记每个位置是否有树
// 初始值为1表示有树，0表示没有树
std::array<int, 10005> result_ary;
int main() {
    // l表示马路长度，m表示需要移除树木的区域数量
    int l, m;
    std::cin >> l >> m;

    // 初始化数组，所有位置都种有树
    result_ary.fill(1);

    // 处理每个需要移除树木的区域
    for (int i = 0; i < m; i++) {
        // a和b分别表示区域的起始和结束位置
        int a, b;
        std::cin >> a >> b;
        // 将区域内的所有树木标记为已移除（值设为0）
        for (int j = a; j <= b; j++) {
            result_ary.at(j) = 0;
        }
    }

    // 统计剩余树木的数量
    int count = 0;
    for (int i = 0; i <= l; i++) {
        if (result_ary.at(i)) {
            count++;
        }
    }

    // 输出结果
    std::cout << count;
    return 0;
}
