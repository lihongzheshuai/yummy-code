/**
 * 题目: 【GESP】C++二级练习 luogu-B3699 [语言月赛202301] 就要 62
 * 题号: B3699
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3699/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    // 条件一：判断原始数字是否能被 62 整除
    if (x % 62 == 0) {
        cout << "Yes" << endl;
        return 0;
    }

    // 条件二：通过循环逐位判断是否包含连续的 "62"
    long long temp = x;
    while (temp > 0) {
        // 判断当前数字末两位是否为 62
        if (temp % 100 == 62) {
            cout << "Yes" << endl;
            return 0;
        }
        // 去掉末尾一位数字，继续向左检查
        temp /= 10;
    }

    // 两个条件均未满足，输出 No
    cout << "No" << endl;
    return 0;
}
