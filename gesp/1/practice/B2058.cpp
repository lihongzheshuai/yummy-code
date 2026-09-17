/**
 * 题目: 【GESP】C++一级练习 luogu-B2058, 奥运奖牌计数
 * 题号: B2058
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2058/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std; // 使用标准命名空间

int main() {
    int n; // 定义变量n，用于存储决赛项目的天数
    cin >> n; // 从输入流中读取n的值
    int a, b, c; // 定义变量a、b、c，用于存储每天获得的金、银、铜牌数目
    int ans = 0, bns = 0, cns = 0; // 初始化变量ans、bns、cns，用于存储金、银、铜牌的总数
    for (int i = 1; i <= n; i++) { // 从1到n的循环，模拟每一天的统计
        cin >> a >> b >> c; // 从输入流中读取每天的金、银、铜牌数目
        ans += a; // 累加金牌数目
        bns += b; // 累加银牌数目
        cns += c; // 累加铜牌数目
    }
    cout << ans << " " << bns << " " << cns << " " << ans + bns + cns; // 输出金、银、铜牌的总数及总奖牌数
    return 0; // 返回0，表示程序执行成功
}
