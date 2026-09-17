/**
 * 题目: 【GESP】C++二级练习 luogu-B3677, [语言月赛202211] Fear
 * 题号: B3677
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3677/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    long long y, t; // 定义两个长整型变量y和t
    cin >> y >> t; // 从输入流中读取y和t的值
    if (t == 0) { // 如果t等于0
        cout << "NO" << endl; // 输出"NO"
        cout << "YES"; // 输出"YES"
    } else { // 否则
        if (t % 2 == 0) { // 如果t是偶数
            cout << "NO" << endl; // 输出"NO"
            if (y % 2 == 0) { // 如果y是偶数
                cout << "NO"; // 输出"NO"
            } else { // 否则
                cout << "YES"; // 输出"YES"
            }
        } else { // 如果t是奇数
            if (y < 0) { // 如果y是负数
                cout << "YES" << endl; // 输出"YES"
            } else { // 否则
                cout << "NO" << endl; // 输出"NO"
            }
            if (y % 2 == 0) { // 如果y是偶数
                cout << "NO"; // 输出"NO"
            } else { // 否则
                cout << "YES"; // 输出"YES"
            }
        }
    }
    return 0; // 返回0，表示程序执行成功
}
