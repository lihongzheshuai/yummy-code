/**
 * 题目: 【GESP】C++一级练习 bcqm-3151, 输出奇偶数之和
 * 题号: 
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm-3151/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 输入的数字n
    int a;
    cin >> a;
    // 奇数和
    int ans = 0;
    // 偶数和
    int sum = 0;
    // 循环计算奇数和：从1开始，每次加2得到下一个奇数
    for (int i = 1; i <= a; i += 2) {
        ans += i;
    }
    // 循环计算偶数和：从0开始，每次加2得到下一个偶数
    for (int i = 0; i <= a; i += 2) {
        sum += i;
    }
    // 按格式输出：偶数和 奇数和
    cout << sum << " " << ans;
    return 0;
}
