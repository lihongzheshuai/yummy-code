/**
 * 题目: 【GESP】C++一级练习 luogu-B2057, 最高的分数
 * 题号: B2057
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2057/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义整数n，用于存储学生人数
    cin >> n; // 从输入流中读取n的值
    int max = 0; // 初始化最大分数为0
    int point; // 定义整数point，用于存储每个学生的分数
    for (int i = 1; i <= n; i++) { // 循环n次，处理每个学生的分数
        cin >> point; // 从输入流中读取每个学生的分数
        if (point > max) { // 如果当前分数大于最大分数
            max = point; // 更新最大分数
        }
    }
    cout << max; // 输出最大分数
    return 0; // 返回0，表示程序执行成功
}
