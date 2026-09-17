/**
 * 题目: 【GESP】C++一级练习BCQM3053，三位数数字交换
 * 题号: 3053
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3053/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a; // 输入一个三位数
    int b, c, d;
    b = a % 10; // 取出个位
    c = a / 10 % 10; // 取出十位
    d = a / 10 / 10; // 取出百位
    int e;
    e = b * 100 + c * 10 + d; // 重新组合数字，个位变百位，百位变个位
    cout << e; // 输出结果
    return 0;
}
