/**
 * 题目: 【GESP】C++一级真题(202406)luogu-B4000，休息时间
 * 题号: B4000
 * 归属: GESP1级 (202406认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4000/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量h, m, s, k来存储输入的时、分、秒和学习时间
    int h, m, s, k;
    // 从标准输入流中读取时、分、秒和学习时间
    cin >> h >> m >> s >> k;
    // 将学习时间转换为小时数并加到h中
    h +=  k / 3600;
    // 计算学习时间剩余的秒数
    int last = k % 3600;
    // 将剩余秒数转换为分钟数并加到m中
    m += last /60;
    // 计算剩余的秒数
    last = last % 60;
    // 将剩余秒数加到s中
    s += last;
    // 如果秒数超过60，则进位到分钟
    if (s >= 60) {
        m++;
        s -= 60;
    }
    // 如果分钟数超过60，则进位到小时
    if (m >= 60) {
        h++;
        m -= 60;
    }
    // 输出休息时刻的时、分、秒
    cout << h << " " << m << " " << s;
    return 0;
}
