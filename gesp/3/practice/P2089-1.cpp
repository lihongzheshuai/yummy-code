/**
 * 题目: 【GESP】C++三级、四级练习 luogu-P2089 烤鸡
 * 题号: P2089
 * 归属: GESP3级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p2089/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> path;              // 记录当前递归路径上的配料质量
vector<vector<int>> results;   // 暂存所有满足条件的搭配方案

// step: 当前正在决定第 step 种配料 (0 ~ 9)
// current_sum: 当前已放入配料的质量之和
void dfs(int step, int current_sum) {
    // 递归边界：10 种配料均已决策完毕
    if (step == 10) {
        if (current_sum == n) {
            results.push_back(path);
        }
        return;
    }

    // 可行性剪枝：
    // 剩余未决策的配料数为 10 - step
    // 即使剩余全部放最小值 1 克，或者全部放最大值 3 克
    int remaining = 10 - step;
    if (current_sum + remaining * 1 > n || current_sum + remaining * 3 < n) {
        return; // 无论后续怎么放都不可能达到目标 n，直接回溯
    }

    // 按升序 1 -> 2 -> 3 尝试每种可能的配料质量，保证字典序
    for (int weight = 1; weight <= 3; ++weight) {
        path.push_back(weight);               // 1. 做出选择
        dfs(step + 1, current_sum + weight);  // 2. 深入下一层
        path.pop_back();                      // 3. 撤销选择（恢复现场）
    }
}

int main() {
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) {
        return 0;
    }

    // 极值特判：10种配料最小和为10，最大和为30
    if (n < 10 || n > 30) {
        cout << 0 << "\n";
        return 0;
    }

    // 从第 0 种配料、当前总和为 0 开始深搜
    dfs(0, 0);

    // 第一行输出方案总数
    cout << results.size() << "\n";

    // 逐行输出每种搭配方案
    for (const auto& scheme : results) {
        for (int i = 0; i < 10; ++i) {
            cout << scheme[i] << (i == 9 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
