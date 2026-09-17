/**
 * 题目: 【GESP】C++一级真题练习(202309)luogu-B3864，小明的幸运数
 * 题号: B3864
 * 归属: GESP1级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3864/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义变量:lucky表示幸运数k，first和end表示区间范围[L,R]
    int lucky, first, end;

    // 读取输入:幸运数k和区间范围[L,R]
    cin >> lucky >> first >> end;

    // 定义sum变量，用于累加幸运数
    int sum = 0;

    // 遍历区间[L,R]
    for (int i = first; i <= end; i++) {
        // 判断条件：个位数为k或者是k的倍数
        if (i % 10 == lucky || i % lucky == 0) {
            // 累加符合条件的数
            sum += i;
        }
    }

    // 输出结果
    cout << sum;
    return 0;
}
