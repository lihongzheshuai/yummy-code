/**
 * 题目: 【GESP/CSP练习】GESP四级 / CSP-J 题解：luogu-P1271 【深基9.例1】选举学生会
 * 题号: P1271
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p1271-counting-sort/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P1271 【深基9.例1】选举学生会
 * Algorithm: 计数排序 (Counting Sort) 与初级排序
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

// 计数数组（桶）：由于候选人编号范围是 1 ~ n，且 n <= 999
// 在全局数据区定义静态数组，大小开至 1005，自动零初始化，杜绝函数内使用局部变长数组 (VLA)
const int MAXN = 1005;
int cnt[MAXN];

int main() {
    int n, m;
    // 读入候选人数量 n 与选票总数 m
    cin >> n >> m;

    // 循环读入 m 张选票，在对应候选人编号的桶中累加得票数
    for (int i = 0; i < m; ++i) {
        int vote;
        cin >> vote;
        cnt[vote]++;
    }

    // 按照候选人编号从 1 到 n 升序遍历，展开输出所有选票
    bool is_first = true; // 用于精准控制数字之间的空格分隔
    for (int i = 1; i <= n; ++i) {
        // 当候选人 i 仍有剩余票数时，持续输出编号 i
        while (cnt[i] > 0) {
            if (!is_first) {
                cout << " ";
            }
            cout << i;
            is_first = false;
            cnt[i]--; // 票数递减
        }
    }
    cout << "\n";

    return 0;
}
