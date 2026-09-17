/**
 * 题目: 【GESP】C++二级练习 luogu-b3685, [语言月赛202212] 计算
 * 题号: B3685
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3685/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    int ans = 0; // 初始化变量ans为0
    while (n != 0) { // 当n不为0时循环
        ans += n % 10; // 将n的最后一位数字加到ans中
        n /= 10; // 将n除以10，去掉最后一位数字
    }
    int count = pow(ans, 2); // 计算ans的平方
    int count_2 = pow(ans, 3); // 计算ans的立方
    cout << ans << endl << count << endl << count_2; // 输出ans、ans的平方和ans的立方
    return 0;
}
