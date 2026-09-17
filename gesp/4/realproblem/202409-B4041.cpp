/**
 * 题目: 【GESP】C++四级真题 luogu-B4041 [GESP202409 四级] 区间排序
 * 题号: B4041
 * 归属: GESP4级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4041/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 定义数组存储序列，由于n<=100，定义105大小足够
int num_ary[105];

int main() {
    // 读入序列长度n
    int n;
    std::cin >> n;

    // 读入n个正整数，存入数组
    for (int i = 0; i < n; i++) {
        std::cin >> num_ary[i];
    }

    // 读入排序操作次数q
    int q;
    std::cin >> q;

    // 执行q次排序操作
    for (int i = 0; i < q; i++) {
        // 读入每次操作的区间范围[l,r]
        int l, r;
        std::cin >> l >> r;

        // 使用std::sort对区间[l,r]进行升序排序
        // 注意：数组下标从0开始，所以要减1
        // sort的区间是左闭右开[first, last)，所以r不用减1
        std::sort(num_ary + l - 1, num_ary + r);
    }

    // 输出最终序列
    for (int i = 0; i < n; i++) {
        std::cout << num_ary[i] << " ";
    }
    return 0;
}
