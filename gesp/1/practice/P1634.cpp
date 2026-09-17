/**
 * 题目: 【GESP】C++一级练习 luogu-P1634, 禽兽的传染病
 * 题号: P1634
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1634/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    long long a, b; // 定义两个长整型变量 a 和 b
    cin >> a >> b; // 从标准输入读取 a 和 b 的值
    long long ans = 1; // 初始化答案为 1

    // 循环 b 次，计算被传染的禽兽数量
    for (long long i = 0; i < b; i++) {
        ans = ans + ans * a; // 更新答案，当前答案加上当前答案乘以 a
    }

    cout << ans; // 输出最终的答案
    return 0; // 返回 0，表示程序正常结束
}
