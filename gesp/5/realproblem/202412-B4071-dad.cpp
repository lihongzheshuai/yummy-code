#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    int n, m;
    std::cin >> n >> m;

    // 武器1的初始材料数量
    int cnt1 = 0;
    // 存储其他武器的材料成本，按武器ID分组。
    // 每个向量都会排序，以便轻松选取最便宜的材料进行移动。
    std::vector<std::vector<int>> others(n + 1);

    for (int i = 0; i < m; ++i) {
        int p, c;
        std::cin >> p >> c;
        if (p == 1) {
            cnt1++;
        } else {
            others[p].push_back(c);
        }
    }

    // 将每种武器（从2到n）的成本按升序排序。
    // 这样如果需要的话，我们可以轻松选择最便宜的材料进行移动。
    for (int i = 2; i <= n; ++i) {
        std::sort(others[i].begin(), others[i].end());
    }

    long long min_total_cost = -1;

    // 遍历 'limit' 的所有可能值。
    // 'limit' 代表任何武器 j（其中 j != 1）允许的最大材料数量。
    // 我们希望 cnt1 > limit，这意味着 cnt1 >= limit + 1。
    // 'limit' 的范围可以从 0（意味着其他武器必须有 0 个材料）到 m（意味着其他武器最多可以有 m 个材料）。
    // 如果 limit = m，那么 cnt1 必须至少为 m+1，如果总材料数为 m，这是不可能的。
    // 因此，m 的上限是安全的，因为不可能的情况会被处理。
    for (int limit = 0; limit <= m; ++limit) {
        long long current_cost = 0;
        int current_cnt1 = cnt1;
        // 'pool' 将存储那些 *不是* 强制从其他武器移动的材料的成本，
        // 但如果需要满足 cnt1 >= limit + 1，可以将它们移动到武器 1。
        std::vector<int> pool;

        // 处理从 2 到 n 的每种武器
        for (int i = 2; i <= n; ++i) {
            int sz = others[i].size();
            // 'keep' 是我们在武器 'i' 处可以保留的最大材料数量（最多 'limit'）
            int keep = std::min(sz, limit);
            // 'move' 是必须从武器 'i' 移动的材料数量
            // 以确保其数量不超过 'limit'。这些是最便宜的。
            int move = sz - keep;
            
            // 强制移动：增加成本并增加 current_cnt1
            for (int j = 0; j < move; ++j) {
                current_cost += others[i][j];
                current_cnt1++;
            }
            
            // 武器 'i' 处的剩余材料（如果有）可以作为候选项移动到武器 1。
            // 将它们的成本添加到 'pool' 中。
            for (int j = move; j < sz; ++j) {
                pool.push_back(others[i][j]);
            }
        }

        // 在考虑所有强制移动后，检查 current_cnt1 是否满足条件 (cnt1 >= limit + 1)
        // 'needed' 是需要从 'pool' 移动到武器 1 的额外材料数量。
        int needed = std::max(0, (limit + 1) - current_cnt1);

        // 如果 'pool' 中没有足够的材料来满足 'needed'，则此 'limit' 不可能。
        if (needed > pool.size()) {
            continue; // 尝试下一个 'limit'
        }

        // 如果需要额外的材料，对 'pool' 进行排序并选取最便宜的。
        if (needed > 0) {
            std::sort(pool.begin(), pool.end());
            for (int i = 0; i < needed; ++i) {
                current_cost += pool[i];
            }
        }

        // 更新目前找到的最小总成本。
        if (min_total_cost == -1 || current_cost < min_total_cost) {
            min_total_cost = current_cost;
        }
    }

    std::cout << min_total_cost << std::endl;

    return 0;
}