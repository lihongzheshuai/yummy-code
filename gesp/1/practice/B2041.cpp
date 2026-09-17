/**
 * 题目: 【GESP】C++一级练习 luogu-B2041, 收集瓶盖赢大奖
 * 题号: B2041
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2041/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取印有“幸运”的瓶盖数
    int n;
    cin >> n;
    // 读取印有“鼓励”的瓶盖数
    int y;
    cin >> y;
    // 判断是否可以兑换大奖
    if (n >= 10 || y >= 20) {
        // 如果可以兑换大奖，输出1
        cout << "1";
    } else {
        // 如果不能兑换大奖，输出0
        cout << "0";
    }
    return 0;
}
