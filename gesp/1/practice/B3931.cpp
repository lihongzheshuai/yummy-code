/**
 * 题目: 【GESP】C++一级练习 luogu-B3931, [语言月赛 202402] 射箭
 * 题号: B3931
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3931/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std; // 使用标准命名空间

int main() {
    int a, b, c; // 定义三个整数变量
    cin >> a >> b >> c; // 从输入流中读取三个整数
    int ans = 0; // 初始化答案变量为0

    // 检查是否发生「神秘事件」，即是否有一个数大于其他两个数之和
    if (a > b + c || b > a + c || c > a + b) {
        ans += 1; // 如果发生「神秘事件」，则答案加1
    }
    cout << ans; // 输出答案
    return 0; // 返回0，表示程序执行成功
}
