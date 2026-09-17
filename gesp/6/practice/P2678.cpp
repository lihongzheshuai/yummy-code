/**
 * 题目: 【NOIP】2015真题解析 luogu-P2678 跳石头（适合GESP六级以上练习）
 * 题号: P2678
 * 归属: GESP6级
 * 博客: https://www.coderli.com/noip-2015-luogu-p2678/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 岩石位置数组（下标 0 存起点，1~N 存中间岩石，N+1 存终点）
int d[50005];

int main() {
    int L, N, M;
    std::cin >> L >> N >> M;

    // 读入 N 块岩石的位置
    for (int i = 1; i <= N; i++) {
        std::cin >> d[i];
    }

    // 起点和终点
    d[0] = 0;
    d[N + 1] = L;

    // 二分答案：搜索"最短跳跃距离"的最大值
    int lo = 1, hi = L, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        // 贪心验证：最短跳跃距离至少为 mid 时，需要移走多少块岩石
        int removed = 0; // 移走的岩石计数
        int last = 0;    // 上一块保留的岩石的位置（从起点开始）
        for (int i = 1; i <= N; i++) {
            if (d[i] - last < mid) {
                // 当前岩石与上一块保留的岩石距离不够，移走
                removed++;
            } else {
                // 距离足够，保留当前岩石
                last = d[i];
            }
        }
        // 检查最后保留的岩石到终点的距离
        if (L - last < mid) {
            removed++;
        }

        // 判断可行性
        if (removed <= M) {
            // 移走的岩石数不超过 M，mid 可行，尝试更大的值
            ans = mid;
            lo = mid + 1;
        } else {
            // 需要移走的岩石太多，mid 不可行，缩小搜索范围
            hi = mid - 1;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
