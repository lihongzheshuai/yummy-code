/**
 * 题目: 【GESP】C++二级练习 luogu-b2081, 与 7 无关的数
 * 题号: B2081
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2081/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std; // 使用标准命名空间
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    int ans = 0; // 初始化答案变量
    for (int i = 1; i <= n; i++) { // 从1到n遍历所有数
        if (i % 7 != 0 && i % 10 != 7 && i / 10 % 10 != 7) { // 判断i是否与7无关
            ans += i * i; // 如果与7无关，则将i的平方加到答案中
        }
    }
    cout << ans; // 输出答案
    return 0;
}
