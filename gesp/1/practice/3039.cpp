/**
 * 题目: 【GESP】C++一级练习BCQM3039，商和余数计算
 * 题号: 3039
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3039/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int a, b;
    // 输入被除数 a 和除数 b
    cin >> a >> b;
    // a / b 计算整数商，a % b 计算余数，中间用空格隔开
    cout << a / b << " " << a % b;
    return 0;
}
