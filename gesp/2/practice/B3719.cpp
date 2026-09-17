/**
 * 题目: 【GESP】C++二级练习 luogu-B3719 [语言月赛202303] Factorial B
 * 题号: B3719
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3719/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义整数变量 n
    cin >> n; // 从标准输入读取整数 n
    if (n >= 4) { // 如果 n 大于等于 4
        cout << "Yes"; // 输出 "Yes"
    } else { // 否则
        cout << "No"; // 输出 "No"
    }
    return 0; // 返回 0，表示程序正常结束
}
