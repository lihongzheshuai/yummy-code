/**
 * 题目: 【GESP】C++二级练习 luogu-b2038, 奇偶 ASCII 值判断
 * 题号: B2038
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2038/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    char n; // 定义字符变量n
    cin >> n; // 读取输入的字符
    if ((int)n % 2 != 0) { // 如果n的ASCII值为奇数
        cout << "YES"; // 输出YES
    } else { // 否则
        cout << "NO"; // 输出NO
    }
    return 0;
}
