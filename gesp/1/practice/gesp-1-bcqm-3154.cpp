/**
 * 题目: 【GESP】C++一级练习 bcqm-3154, 偶数求和
 * 题号: 
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm-3154/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 输入数字的个数
    int a;
    cin >> a;

    // 用于存储每次输入的数字
    int d;
    // 用long long存储累加和，防止溢出
    long long ans = 0;

    // 循环读入a个数字
    for (int i = 0; i < a; i++) {
        cin >> d;
        // 如果是偶数则累加
        if (d % 2 == 0) {
            ans += d;
        }
    }

    // 输出结果
    cout << ans;
    return 0;
}
