/**
 * 题目: 【CSP】CSP-J 2021真题 | 分糖果 luogu-P7909 （适合GESP三级及以上考生练习）
 * 题号: P7909
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2021-p7909/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n, L, R;
    std::cin >> n >> L >> R;

    int ans;
    int sub = R - L; // 计算可供选择拿取糖果数量的变化空间（跨度）

    if (sub >= n) {
        // 如果跨度长于或等于一个完整的分配周期 n
        // 那么这期间必然会经过余数循环清零的分界点，而在清零前余数必定为最大极限值 (n - 1)
        ans = n - 1;
    } else {
        // 如果跨度小于一个分配周期 n，也就是不够凑出新的一轮
        int l_mod = L % n;           // 最小值 L 在分配后原本能剩下的基础余数
        int l_mod_sum = l_mod + sub; // 拿最多的糖果时，理论上余数跟着叠加了增加的幅度 sub

        if (l_mod_sum >= n) {
            // 如果叠加后的最终余量达到了周期 n，意味着后来增加的糖果导致又凑够了完整的一轮
            // 其内在必定经历了一次越界前余数顶格的时刻（取得最大值 n - 1）
            ans = n - 1;
        } else {
            // 如果拿取最大空间也没有触及到新一轮的分界线（也就是没有引发被小朋友分走）
            // 那么自然是体力越好拿得越多，剩下的奖励就越大，此时直接取得最大余量
            ans = l_mod_sum; // 其实也就等效于 R % n
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
