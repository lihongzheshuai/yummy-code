/**
 * 题目: 【GESP】C++一级练习 bcqm-3173, 上课点名
 * 题号: 
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm-3173/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取总共需要到位的学生个数
    int a;
    cin >> a;
    // 初始化变量b用于读取到位的学生学号
    int b;
    // 初始化变量ans用于计算所有学生学号的和
    int ans = 0;
    // 初始化变量sum用于计算到位的学生学号的和
    int sum = 0;
    // 计算所有学生学号的和
    for (int i = 1; i <= a; i++) {
        ans += i;
    }
    // 读取到位的学生学号并计算到位的学生学号的和
    for (int i = 2; i <= a; i++) {
        cin >> b;
        sum += b;
    }
    // 输出缺席的学生学号
    cout << ans - sum;
    return 0;
}
