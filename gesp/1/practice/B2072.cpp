/**
 * 题目: 【GESP】C++一级练习 luogu-B2072, 分苹果
 * 题号: B2072
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2072/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int n; // 定义变量n，用于存储输入的整数
    cin >> n; // 从标准输入读取整数n
    int ans = 0; // 初始化变量ans，用于存储累加的结果
    for (int i = 1; i <= n; i++) { // 遍历从1到n的所有整数
        ans += i; // 将当前整数累加到ans中
    }
    cout << ans; // 输出累加的结果
    return 0; // 返回0，表示程序执行成功
}
