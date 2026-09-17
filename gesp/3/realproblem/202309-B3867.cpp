/**
 * 题目: 【GESP】C++三级真题 luogu-B3867 [GESP202309 三级] 小杨的储蓄
 * 题号: B3867
 * 归属: GESP3级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3867/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量N和D，分别表示存钱罐数量和天数
    int N, D;
    std::cin >> N >> D;

    // 创建数组存储每个存钱罐的金额，初始化为0
    int ary[N] = {0};

    // 循环D天，每天读取存钱罐编号并累加对应金额
    for (int i = 1; i <= D; i++) {
        int idx;
        std::cin >> idx;
        ary[idx] += i;  // 第i天存入i元钱
    }

    // 输出每个存钱罐的最终金额
    for (int i = 0; i< N; i++) {
        std::cout << ary[i] << " ";
    }
    return 0;
}
