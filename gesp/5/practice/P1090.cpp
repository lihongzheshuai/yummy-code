/**
 * 题目: 【GESP/CSP练习】GESP五级 / CSP-J 题解：luogu-P1090 [NOIP2004 提高组] 合并果子
 * 题号: P1090
 * 归属: GESP5级 / CSP-J
 * 博客: https://www.coderli.com/gesp-5-luogu-p1090-merge-fruit/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 使用小顶堆（优先队列）维护当前所有果子堆的重量
    // greater<long long> 表示堆顶始终保持当前所有元素中的最小值
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // 读取 n 堆果子的初始重量并依次压入小顶堆中
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    // 记录合并果子总共消耗的最小体力
    long long total_cost = 0;

    // 每次合并必定选出当前最小的两堆果子（贪心策略 / 哈夫曼树构建过程）
    // 经过 n - 1 次合并后，优先队列中最终只剩下 1 堆果子
    while (pq.size() > 1) {
        // 取出当前重量最小的第一堆
        long long first = pq.top();
        pq.pop();

        // 取出当前重量最小的第二堆
        long long second = pq.top();
        pq.pop();

        // 两堆合并所消耗的体力等于两堆重量之和
        long long merged = first + second;
        total_cost += merged;

        // 将合并生成的新果子堆放回小顶堆中，参与后续的合并
        pq.push(merged);
    }

    // 输出最小总体力消耗值（若 n = 1，无需合并，输出 0）
    cout << total_cost << endl;

    return 0;
}
