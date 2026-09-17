/**
 * P3353 在你窗外闪耀的星星 - AI Solution
 *
 * 核心思路：
 * 题目要求求出调整窗户位置后能看到的星星亮度之和的最大值。
 * 窗户的覆盖范围为 W。通过分析样例和题目逻辑（特别是样例输出
 * 16），我们可以推断出： 当窗户宽度参数为 W
 * 时，它实际上能覆盖的坐标跨度限制是星星坐标差值 + 1 <= W， 即能够覆盖 W
 * 个连续的整数坐标位置。
 *
 * 我们可以使用前缀和（Prefix Sum）算法来解决这个问题：
 * 1. 使用一个数组 light[] 记录每个坐标位置上的星星总亮度。
 *    注意题目提到“一个位置可能有多颗星星”，所以需要累加。
 * 2. 计算 light[] 的前缀和数组 sum[]，其中 sum[i] 表示从坐标 1 到 i 的总亮度。
 * 3. 枚举所有可能的窗户结束位置 i（从 1 到 100000）。
 *    对于结束位置 i，窗户的起始位置大约是 i - W + 1。
 *    该窗口内的亮度和可以通过 sum[i] - sum[i - W] 快速计算得出。
 *    (若 i < W，则等价于 sum[i] - sum[0])。
 * 4. 遍历过程中维护最大值即可。
 *
 * 对于特殊情况 W=0，根据前缀和公式 sum[i] - sum[i] 计算结果为
 * 0，符合通常的题目设定（W=0 看不到星星）。
 *
 * 时间复杂度：
 * - 输入处理：O(N)
 * - 前缀和计算与枚举：O(X_max)，其中 X_max = 100000。
 * - 总时间复杂度：O(N + X_max)，非常高效。
 */

#include <algorithm>
#include <iostream>
#include <vector>

const int MAX_X = 100005;

// 使用 long long 防止亮度总和溢出（虽然本题数据范围 int 可能够用，但 long long
// 更稳妥）
typedef long long ll;

int main() {
    // 优化 I/O 性能
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, w;
    if (!(std::cin >> n >> w)) return 0;

    // light 数组存储每个坐标点的亮度
    // 题目坐标范围 1 <= Xi <= 100000
    std::vector<int> light(MAX_X + 1, 0);

    // 读取星星数据
    for (int i = 0; i < n; ++i) {
        int x, b;
        std::cin >> x >> b;
        // 只有在有效范围内才记录（虽然题目保证 1<=Xi<=100000）
        if (x >= 0 && x < MAX_X) {
            light[x] += b;
        }
    }

    // 计算前缀和
    // pre[i] 表示 light[0]...light[i] 的和
    std::vector<ll> pre(MAX_X + 1, 0);
    for (int i = 1; i < MAX_X; ++i) {
        pre[i] = pre[i - 1] + light[i];
    }

    ll max_brightness = 0;

    // 遍历所有可能的窗口结束位置 i
    // 窗口长度参数为 w，对应覆盖 w 个单位长度（即 sum[i] - sum[i-w]）
    // 参考样例 W=3，结果16（覆盖2,3,4），说明覆盖了3个点。
    for (int i = 1; i < MAX_X; ++i) {
        // 计算窗口起始索引的前一个位置
        int prev_idx = i - w;

        // 边界处理：如果 prev_idx < 0，说明窗口从 1 开始（或者更早，但在 1
        // 之前为 0）
        ll current_window_sum = 0;
        if (prev_idx < 0) {
            current_window_sum = pre[i];  // 相当于 pre[i] - pre[0]
        } else {
            current_window_sum = pre[i] - pre[prev_idx];
        }

        if (current_window_sum > max_brightness) {
            max_brightness = current_window_sum;
        }
    }

    std::cout << max_brightness << std::endl;

    return 0;
}
