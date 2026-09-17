/**
 * 题目: 【GESP】C++一级真题练习(202312)luogu-B3921，小杨的考试
 * 题号: B3921
 * 归属: GESP1级 (202312认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b3921/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量a表示当前星期数，b表示还有多少天考试
    int a, b;
    // 从标准输入读取a和b的值
    cin >> a >> b;
    // 计算考试那天的星期数：当前星期数加上天数后对7取余
    int ans = (a + b) % 7;
    // 如果余数为0，表示是星期天，根据题目要求用7表示
    if (ans == 0) {
        ans = 7;
    }
    // 输出结果
    cout << ans;
    return 0;
}
