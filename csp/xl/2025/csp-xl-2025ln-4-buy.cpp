/**
 * 题目: 【CSP】CSP-XL 2025辽宁复赛真题-第四题, 购物（buy）
 * 题号: 
 * 归属: CSP-J
 * 博客: https://www.coderli.com/csp-xl-2025ln-4-buy/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
long long a[25][2];      // a[i][0] 表示第 i 件物品方案一的花费，a[i][1] 表示方案二的花费
long long sum = 0;       // 当前已选物品的总花费
long long n, S;          // n 件物品，预算上限为 S
long long ans = 0;       // 记录总花费不超过 S 的合法方案数

// 深度优先搜索，count 表示当前正在决策第 count 件物品（0-based）
void dfs(int count) {
    if (count == n) {               // 所有物品决策完毕
        if (sum <= S) {             // 若总花费不超预算，则方案合法
            ans++;
        }
        return;
    }
    // 对第 count 件物品，分别尝试“不选”与“选”两种选择
    for (int i = 0; i <= 1; i++) {
        sum += a[count][i];         // 累加当前选择的花费
        dfs(count + 1);             // 递归决策下一件物品
        sum -= a[count][i];         // 回溯，撤销当前选择的花费
    }
    return;
}

int main() {
    freopen("buy.in", "r", stdin);   // 按复赛要求重定向输入
    freopen("buy.out", "w", stdout); // 按复赛要求重定向输出
    std::cin >> n >> S;              // 读入物品件数 n 与预算上限 S

    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1]; // 读入每件物品不选/选的花费
    }

    dfs(0);                          // 从第 0 件物品开始搜索

    std::cout << ans;                // 输出合法方案总数
    return 0;
}
