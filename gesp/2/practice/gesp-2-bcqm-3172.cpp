/**
 * 题目: 【GESP】C++二级练习 bcqm-3172, 短信计费
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-bcqm-3172/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a; // 读取发送短信的总次数
    cin >> a;
    int b; // 读取每条短信的字数
    double ans = 0; // 初始化总资费为0
    for (int i = 1; i <= a; i++) {
        cin >> b; // 读取每条短信的字数
        if (b <= 70) {
            ans += 0.1; // 如果字数不超过70，则增加0.1元的资费
        }
        if (b > 70) {
            if (b % 70 == 0) {
                ans += b / 70 * 0.1; // 如果字数是70的整数倍，则增加相应的资费
            }
            if (b % 70 != 0) {
                ans += (b / 70 + 1) * 0.1; // 如果字数不是70的整数倍，则增加相应的资费，并考虑多出的字数
            }
        }
    }
    printf("%.1f", ans); // 输出总资费，保留一位小数
    return 0;
}
