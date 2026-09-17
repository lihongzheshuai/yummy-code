/**
 * 题目: 【GESP】C++二级练习 luogu-b3687, [语言月赛202212] 数字口袋
 * 题号: B3687
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3687/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 输入的整数
    cin >> n; // 从输入流中读取整数
    int ans = 0; // 初始化答案
    for (int i = 1;; i++) { // 从1开始的无限循环
        if (ans + i > n) { // 如果当前答案加上i超过n，则退出循环
            break;
        }
        cout << i << endl; // 输出当前数
        ans += i; // 更新答案
    }
    return 0;
}
