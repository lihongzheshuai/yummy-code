/**
 * 题目: 【GESP】C++一级练习 luogu-B2060, 满足条件的数累加
 * 题号: B2060
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2060/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int m, n; // 定义变量m和n
    cin >> m >> n; // 从输入流中读取m和n的值
    int ans = 0; // 初始化变量ans，用于存储累加的结果
    for (int i = m; i <= n; i++) { // 从m到n的循环
        if (i % 17 == 0) { // 如果i能被17整除
            ans += i; // 将i累加到ans中
        }
    }
    cout << ans; // 输出累加的结果
    return 0; // 返回0，表示程序执行成功
}
