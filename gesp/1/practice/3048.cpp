/**
 * 题目: 【GESP】C++一级练习BCQM3048，顺序执行、逆推运算
 * 题号: 3048
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3048/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x; // 输入总钱数

    // 最终状态：三人钱数相等，都是总钱数的三分之一
    int avg = x / 3;
    int first, second, third;

    // 第三次分钱后，达到最终状态
    // 从最终状态逆推丙分给甲乙之前
    first = avg / 2; // 甲的钱变成了现在的一半
    second = avg / 2; // 乙的钱变成了现在的一半
    third = avg + first + second; // 丙分出去了甲乙现在的钱数，所以加上这些

    // 逆推乙分给甲丙之前
    first = first / 2; // 甲的钱变成了现在的一半
    third = third / 2; // 丙的钱变成了现在的一半
    second = second + first + third; // 乙分出去了甲丙现在的钱数，所以加上这些

    // 逆推甲分给乙丙之前
    second = second / 2; // 乙的钱变成了现在的一半
    third = third / 2; // 丙的钱变成了现在的一半
    first = first + second + third; // 甲分出去了乙丙现在的钱数，所以加上这些

    // 输出初始状态三人分别的钱数
    cout << first << " " << second << " " << third << endl;
    return 0;
}
