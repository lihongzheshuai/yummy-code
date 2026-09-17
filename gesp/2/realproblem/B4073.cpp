/**
 * 题目: 【CSP】CSP-X 2018真题 | 快递费用 luogu-B4073 （适合GESP二级及以上考生练习）
 * 题号: B4073
 * 归属: GESP2级
 * 博客: https://www.coderli.com/csp-x-2018-b4073/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int w, n;
    std::cin >> w >> n;

    // 五个区域对应的超重加收单价，下标 1~5 对应区域 1~5
    int rate[] = {0, 4, 6, 9, 10, 17};

    // 基础费用 20 元
    int cost = 20;

    // 如果超重，计算超重份数并加收费用
    if (w > 500) {
        // 向上取整：ceil((w-500)/500) = (w-500+499)/500 = (w-1)/500
        int extra = (w - 1) / 500;
        cost += extra * rate[n];
    }

    std::cout << cost << std::endl;
    return 0;
}
