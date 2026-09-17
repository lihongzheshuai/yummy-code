/**
 * 题目: 【CSP】CSP-J 2021真题 | 插入排序 luogu-P7910 （适合GESP四-六级及以上考生练习）
 * 题号: P7910
 * 归属: GESP6级
 * 博客: https://www.coderli.com/csp-j-2021-p7910/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n, Q;
    std::cin >> n >> Q;

    int a[8001];       // 原始数组，下标从 1 开始
    int rnk[8001];     // rnk[i] 表示 a[i] 在插入排序后的位置（排名）

    // 读入初始数组
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    // 预计算初始排名
    // rnk[i] = 1 + 所有"排在 i 前面"的元素个数
    // 元素 j 排在 i 前面的条件：a[j] < a[i]，或 a[j] == a[i] 且 j < i
    for (int i = 1; i <= n; i++) {
        rnk[i] = 1;
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                continue;
            }
            if (a[j] < a[i] || (a[j] == a[i] && j < i)) {
                rnk[i]++;
            }
        }
    }

    // 处理 Q 次操作
    while (Q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            // 修改操作：将 a[x] 改为 v
            int x, v;
            std::cin >> x >> v;
            int old_val = a[x]; // 记录修改前的旧值
            a[x] = v;           // 执行修改

            // 增量更新其他元素的排名
            // 逐一检查每个元素 i 与 x 的相对顺序是否因修改而改变
            for (int i = 1; i <= n; i++) {
                if (i == x) {
                    continue;
                }

                // 修改前，x 是否排在 i 前面？
                bool old_x_before_i = (old_val < a[i]) || (old_val == a[i] && x < i);
                // 修改后，x 是否排在 i 前面？
                bool new_x_before_i = (v < a[i]) || (v == a[i] && x < i);

                if (old_x_before_i && !new_x_before_i) {
                    // x 原来排在 i 前面，现在不再排在前面
                    // i 前面少了一个元素，排名前移 1 位
                    rnk[i]--;
                } else if (!old_x_before_i && new_x_before_i) {
                    // x 原来不排在 i 前面，现在排到了前面
                    // i 前面多了一个元素，排名后移 1 位
                    rnk[i]++;
                }
            }

            // 重新计算 x 自身的排名
            rnk[x] = 1;
            for (int j = 1; j <= n; j++) {
                if (j == x) {
                    continue;
                }
                if (a[j] < a[x] || (a[j] == a[x] && j < x)) {
                    rnk[x]++;
                }
            }
        } else {
            // 查询操作：输出 a[x] 排序后所处的位置
            int x;
            std::cin >> x;
            std::cout << rnk[x] << "\n";
        }
    }

    return 0;
}
