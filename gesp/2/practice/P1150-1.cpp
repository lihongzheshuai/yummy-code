/**
 * 题目: 【GESP】C++二级模拟 luogu-p1150, Peter 的烟
 * 题号: P1150
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-p1150/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long total = n;  // 总共抽的烟数
    long long butts = n;  // 当前的烟蒂数

    while (butts >= k) {
        long long new_cigs = butts / k;  // 可以换到的新烟数
        total += new_cigs;  // 加入到总数中
        butts = butts % k + new_cigs;  // 更新烟蒂数：未换的 + 新抽的
    }

    cout << total << endl;
    return 0;
}
