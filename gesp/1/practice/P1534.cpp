/**
 * 题目: 【GESP】C++一级练习 luogu-P1534, 不高兴的津津（升级版）
 * 题号: P1534
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1534/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a;  // 天数
    cin >> a;
    int b, c;  // b是上学时间，c是上课时间
    int ans = 0;  // 存储最终的不高兴程度总和
    int y = 0;  // 存储前一天剩余的不高兴程度
    for (int i = 1; i <= a; i++) {
        cin >> b >> c;
        int t = (c + b) - 8;  // 计算当天产生的不高兴程度(上学+上课时间-8)
        int t_1 = t + y;  // 当天总的不高兴程度 = 当天产生的 + 前一天剩余的
        ans += t_1;  // 累加到总和中
        y = t_1;  // 更新前一天的不高兴程度
    }
    cout << ans;  // 输出最终的不高兴程度总和
    return 0;
}
