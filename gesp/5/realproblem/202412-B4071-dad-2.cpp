#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main() {
    // n: 武器种类数, m: 强化材料总数
    int n, m;
    std::cin >> n >> m;
    
    // materials[p] 存储适配第 p 种武器的各种强化材料的修改代价
    // 使用 vector 存储以便后续排序和处理
    std::vector<std::vector<int>> materials(n + 1);
    int cnt1 = 0; // 记录适配第 1 种武器的初始材料数量

    for (int i = 0; i < m; i++) {
        int p, c;
        std::cin >> p >> c;
        if (p == 1) {
            // 如果已经是第 1 种武器的材料，直接计数，不需要花费
            cnt1++;
        } else {
            // 否则记录修改该材料适配第 1 种武器所需的费用
            materials[p].push_back(c);
        }
    }

    // 对于除第 1 种以外的每种武器，将其材料按修改代价从小到大排序
    // 这样在需要减少该武器的材料数量时，可以优先移除代价最小的
    for (int i = 2; i <= n; i++) {
        std::sort(materials[i].begin(), materials[i].end());
    }

    long long total_cost = LLONG_MAX; // 初始化最小总花费为最大值

    // 枚举第 1 种武器最终拥有的材料数量 i
    // i 的范围：从当前的 cnt1 开始，直到所有材料都归它 (m)
    // 目标是：第 1 种武器有 i 个材料，且其他所有武器的材料数都 < i (即最多 i-1 个)
    for (int i = cnt1; i <= m; i++) {
        std::vector<int> pool; // 备选池：存储那些虽然不需要强制买（为了压低别人票数），但可以用来凑第 1 种武器票数的材料
        int total_movecount = 0; // 记录为了“压制”其他武器而必须修改的材料数量
        long long cur_cost = 0;  // 当前方案的总花费

        // 遍历所有武器（materials 实际上从下标 2 开始有效，0 和 1 为空或已处理）
        for (int j = 0; j < materials.size(); j++) {
            // 计算第 j 种武器需要移除多少个材料才能使其数量严格小于 i
            // 原有数量 size，目标保留数量 <= i-1
            // 需要移除的数量 = size - (i - 1) = size - i + 1
            // 代码逻辑：move = size - i，则移除下标 0 到 move 的元素（共 move + 1 个）
            // 移除后剩余：size - (size - i + 1) = i - 1 个，满足条件
            int move = materials[j].size() - i;

            for (int k = 0; k < materials[j].size(); k++) {
                if (k <= move) {
                    // 必须修改的材料（为了让该武器材料数 < i）
                    cur_cost += materials[j][k];
                    total_movecount++;
                } else {
                    // 不需要强制修改的材料，放入备选池
                    // 如果后面第 1 种武器的数量还不够 i，可以从这里挑便宜的买
                    pool.push_back(materials[j][k]);
                }
            }
        }

        // 统计目前第 1 种武器的材料数：初始 cnt1 + 强制修改的 total_movecount
        // 如果还不到目标数量 i，需要从备选池中补足
        if (cnt1 + total_movecount < i) {
            // 对备选池按代价排序
            std::sort(pool.begin(), pool.end());
            // 贪心选取最便宜的几个补充，直到达到数量 i
            for (int j = 0; j < i - total_movecount - cnt1; j++) {
                cur_cost += pool[j];
            }
        }

        // 更新全局最小花费
        total_cost = std::min(total_cost, cur_cost);
    }
    std::cout << total_cost;
    return 0;
}