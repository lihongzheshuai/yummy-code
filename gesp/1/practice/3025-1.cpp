/**
 * 题目: 【GESP】C++一级练习BCQM3025，输入-计算-输出-6
 * 题号: 3025
 * 归属: GESP1级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3025/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, a, b, c;
    // 输入班级总人数n，参加语文兴趣小组的人数a，参加数学兴趣小组的人数b，两个小组都参加的人数c
    cin >> n >> a >> b >> c;
    // 计算两个兴趣小组都没有参加的人数：总人数 - (参加语文的人数 + 参加数学的人数 - 两个都参加的人数)
    cout << n - (a + b - c);
    return 0;
}
