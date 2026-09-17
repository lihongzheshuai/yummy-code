/**
 * 题目: 【GESP】C++一级真题练习(202312)luogu-B3921，小杨的考试
 * 题号: B3921
 * 归属: GESP1级 (202312认证真题)
 * 解法: 解法 2 / 共 2 种解法
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
    // 计算增加的天数对7取余，因为7天一个循环，星期不变
    int i = b % 7;
    // 加上原来的星期数，得到考试那天的星期数
    int j = a + i;
    // 如果结果大于7，需要减去7，因为一周只有7天
    if (j > 7) {
        j -= 7;
    }
    // 输出考试那天是星期几
    cout << j;
    return 0;
}
