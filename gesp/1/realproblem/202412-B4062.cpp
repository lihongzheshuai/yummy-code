/**
 * 题目: 【GESP】C++一级真题 luogu-b4062, [GESP202412 一级] 温度转换
 * 题号: B4062
 * 归属: GESP1级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4062/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    // 读取温度值
    double k;
    cin >> k;
    // 计算摄氏温度
    double c = k - 273.15;
    // 计算华氏温度
    double f = c * 1.8 + 32;
    // 检查是否温度过高
    if (f > 212) {
        cout << "Temperature is too high!";
        return 0;
    }
    // 输出摄氏和华氏温度
    printf("%.2f %.2f", c, f);
    return 0;
}
