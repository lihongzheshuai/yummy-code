/*
 * P2696 慈善的约瑟夫
 *
 * 题目分析:
 * 这是一个约瑟夫问题的变种。
 * 每一轮游戏，N个人围成一圈，从第1人开始，每隔1人踢出1人。
 * 根据样例 N=10 -> Output=13 分析：
 * 标准约瑟夫问题中，若每隔1人踢除（即报数1,2，2被踢），幸存者公式为 J(n) = 2*(n
 * - 2^m) + 1，其中 2^m <= n。 样例 N=10，J(10) = 5。
 * 若幸存者为5，且规则是“比幸存者号码高的人每人得到1个金币并离开”，则6,7,8,9,10离开（共5人）。花费5金币。
 * 剩余1,2,3,4,5 (N=5)。
 * J(5) = 2*(5-4)+1 = 3。
 * 规则：比3高的人离开 -> 4, 5离开（2人）。花费2金币。
 * 剩余1,2,3 (N=3)。
 * J(3) = 2*(3-2)+1 = 3。
 * 规则：比3高的人离开 -> 无人离开。
 * 此时人数不再减少。
 * 剩余3人，每人得2金币 -> 3*2 = 6金币。
 * 总金币 = 5 + 2 + 6 = 13。符合样例。
 *
 * 所以算法逻辑为：
 * 1. 计算当前人数n的幸存者 survivor = 2*(n - 2^m) + 1。
 * 2. 离开去的人数 leaving = n - survivor。
 * 3. 累加金币 leaving * 1。
 * 4. 更新 n = survivor。
 * 5. 如果 n 没有变化 (leaving == 0)，结束循环。
 * 6. 最后累加 n * 2 金币。
 */

#include <cmath>
#include <iostream>

using namespace std;

// 计算约瑟夫问题幸存者编号 (k=2)
// 公式: J(n) = 2 * (n - 2^m) + 1, 其中 2^m 是不超过 n 的最大 2 的幂
int get_survivor(int n) {
    if (n <= 1) return 1;
    int m = 1;
    while (m * 2 <= n) {
        m *= 2;
    }
    return 2 * (n - m) + 1;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    long long total_money =
        0;  // 使用 long long 防止溢出，虽然题目 N<=10^5 结果应该不会爆 int

    while (true) {
        int survivor = get_survivor(n);

        // 步骤：比幸存者号码高的人离开
        // 幸存者编号是 survivor，说明留下的是 1..survivor
        // 离开的是 survivor+1 .. n
        int leaving_count = n - survivor;

        if (leaving_count == 0) {
            // 人数不再减少
            break;
        }

        // 离开的人每人得到 1 个金币
        total_money += leaving_count;

        // 更新剩下的人数
        n = survivor;
    }

    // 最后剩下的那些人将得到 2 个金币
    total_money += n * 2;

    cout << total_money << endl;

    return 0;
}
