#include <algorithm>
#include <iostream>
#include <vector>

// P14359 [CSP-J 2025] 异或和
//
// 【题目描述】
// 给定一个长度为 n 的非负整数序列，要求选出尽可能多的**不相交**区间，
// 使得每个区间的异或和都等于给定的常数 k。
//
// 【算法逻辑详细步骤】
//
// 1. **前缀异或和 (Prefix XOR Sum)**
//    定义 pre[i] 表示前 i 个数的按位异或和：
//    pre[i] = a[1] ^ a[2] ^ ... ^ a[i]
//    pre[0] = 0
//    利用异或的性质：
//    1. **交换律 (Commutative Property)**: a ^ b = b ^ a
//       (例子: 3 ^ 5 = 5 ^ 3)
//    2. **结合律 (Associative Property)**: (a ^ b) ^ c = a ^ (b ^ c)
//       (例子: (1 ^ 2) ^ 3 = 1 ^ (2 ^ 3))
//    3. **自反性 (Self-Inverse)**: a ^ a = 0
//
//    区间 [l, r] 的异或和可以表示为：
//    XOR(l, r) = a[l] ^ ... ^ a[r]
//    而 pre[r] ^ pre[l-1] = (a[1] ^ ... ^ a[r]) ^ (a[1] ^ ... ^ a[l-1])
//    根据结合律和交换律，我们可以在不改变结果的情况下重新排列运算顺序：
//    = (a[1] ^ a[1]) ^ ... ^ (a[l-1] ^ a[l-1]) ^ (a[l] ^ ... ^ a[r])
//    因为 a ^ a = 0，相同的项抵消，最终只剩下 a[l] ^ ... ^ a[r]。
//
// 2. **问题转化**
//    我们需要找到尽可能多的区间 [l, r]，满足 pre[r] ^ pre[l-1] == k。
//    这等价于 pre[l-1] == pre[r] ^ k。
//
// 3. **动态规划 (Dynamic Programming) - 举例说明**
//    让我们用样例 1 来模拟一下这个过程：n=4, k=2, 序列 a = [2, 1, 0, 3]。
//    初始化：max_dp[0] = 0 (表示由空前缀得到0个区间)，其余为 -1。dp = 0。
//
//    - **i=1, a=2**:
//      前缀异或 cur_xor = 0 ^ 2 = 2。
//      目标前缀 target = 2 ^ 2 = 0。
//      查找 max_dp[0]，发现是 0。说明可以在前面找到切分点 (位置0)，形成区间 [1,
//      1]。 更新 dp = max_dp[0] + 1 = 1。即区间 [1, 1] (权值2=k)
//      是选中的第1个区间。 更新 max_dp[2] = 1。
//
//    - **i=2, a=1**:
//      cur_xor = 2 ^ 1 = 3。
//      target = 3 ^ 2 = 1。
//      查找 max_dp[1]，是 -1 (没出现过)。无法以 i=2 为结尾形成新区间。
//      dp 保持为 1 (延续 i=1 的结果)。
//      更新 max_dp[3] = 1 (表示前缀异或为3时，最多能有1个区间)。
//
//    - **i=3, a=0**:
//      cur_xor = 3 ^ 0 = 3。
//      target = 3 ^ 2 = 1。
//      查找 max_dp[1]，是 -1。无法以 i=3 为结尾形成新区间。
//      dp 保持为 1。
//      更新 max_dp[3] 保持为 1。
//
//    - **i=4, a=3**:
//      cur_xor = 3 ^ 3 = 0。
//      target = 0 ^ 2 = 2。
//      查找 max_dp[2]，发现是 1 (在 i=1 时存入)。
//      说明存在切分点 j-1 (对应 i=1)，使得区间 [2, 4] 的异或和为 k。
//      即区间 [2, 4] 的异或和 = pre[4] ^ pre[1] = 0 ^ 2 = 2。
//      更新 dp = max_dp[2] + 1 = 1 + 1 = 2。
//      我们找到了两个区间：[1, 1] 和 [2, 4]。
//      更新 max_dp[0] = 2。
//
//    最终结果 dp = 2。
//
// 4. **max_dp 数组详解 (The max_dp Array)**
//    - **定义**: `max_dp[v]` 存储的是，在所有满足 `prefix_xor[idx] == v`
//    的历史位置 `idx` 中，
//      最大的那个 `dp[idx]` 值。
//      即 `max_dp[v] = max { dp[idx] | prefix_xor[idx] == v, idx < current_i
//      }`。
//    - **作用 (Purpose)**:
//      当我们计算当前位置 `i` 的状态时，如果我们要找一个前驱点 `j-1`，
//      使得 `prefix_xor[j-1] == target`，
//      我们希望这个 `j-1` 能提供的 `dp[j-1]` 尽可能大，这样 `dp[i] = dp[j-1] +
//      1` 才会最大。 因此，我们不需要遍历所有可能的 `j-1`，只需要直接查表
//      `max_dp[target]`。
//    - **更新 (Update)**:
//      每当我们计算完一个新的位置 `i` 的 `dp[i]` 后，
//      该位置的前缀异或和为 `current_xor`。
//      我们就用当前的 `dp[i]` 去更新 `max_dp[current_xor]`：
//      `max_dp[current_xor] = max(max_dp[current_xor], dp[i])`。
//      这样，后续的位置在查表时，就能利用到这个最新的、可能更优的结果。
//
// 5. **总结算法流程**
//    - 维护 `max_dp[val]`：记录达到前缀异或和 `val`
//    时，所能拥有的最大不相交区间数。
//    - 遍历数组，计算当前前缀异或 `curr`。
//    - 计算如果当前位置作为区间结尾，需要的前缀异或 `target = curr ^ k`。
//    - 如果 `max_dp[target]` 存在，则尝试更新 `dp = max(dp, max_dp[target] +
//    1)`。
//    - 用当前的 `dp` 更新 `max_dp[curr]`。
//    - 初始化 max_dp 数组，max_dp[0] = 0 (表示前缀和为0时，区间数为0)，其余为
//    -1 (表示不存在)。
//    - 遍历序列，维护当前前缀异或和 current_xor。
//    - 计算目标前缀值 target = current_xor ^ k。
//      尝试更新 dp = max(dp, max_dp[target] + 1)。
//    - 更新 max_dp[current_xor] = max(max_dp[current_xor],
//    dp)，保存当前状态以便后续使用。

const int MAX_VAL = 1 << 20;  // 2^20 = 1048576, 题目限制 a_i < 2^20, k < 2^20
int max_dp[MAX_VAL];

int main() {
    // 优化 I/O 速度，避免大量输入输出导致超时
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    int k;
    if (!(std::cin >> n >> k)) return 0;

    // 初始化 max_dp 数组
    // max_dp[v] 存储的是：当某个位置的前缀异或和为 v
    // 时，该位置及之前能得到的最大区间数
    for (int i = 0; i < MAX_VAL; ++i) {
        max_dp[i] = -1;
    }
    // 初始状态：还没有读取任何数时，前缀异或和为 0，区间数为 0
    max_dp[0] = 0;

    int current_xor = 0;  // 当前的前缀异或和 (pre[i])
    int dp = 0;           // 当前位置的最大区间数 (dp[i])

    for (int i = 1; i <= n; ++i) {
        int a;
        std::cin >> a;
        current_xor ^= a;  // 计算到当前位置 i 的前缀异或和

        // 步骤 A: 尝试以当前位置 i 作为区间的结尾
        // 我们需要找一个之前的断点 j-1，使得 pre[j-1] ^ pre[i] == k
        // 即 pre[j-1] == pre[i] ^ k
        int target = current_xor ^ k;

        // 如果之前存在某个位置的前缀异或和等于 target
        if (max_dp[target] != -1) {
            // 尝试以当前位置为结尾构成一个新区间
            // dp[i] = max(dp[i-1], max_dp[target] + 1)
            // 注意：这里的 dp 变量实际上在迭代过程中一方面代表
            // dp[i-1]，更新后代表 dp[i] 因为 dp[i] 至少是
            // dp[i-1]，所以直接比较即可
            dp = std::max(dp, max_dp[target] + 1);
        }

        // 更新当前前缀异或值的最大 dp 值
        // 如果当前 dp 值比之前记录的更大，则更新
        if (dp > max_dp[current_xor]) {
            max_dp[current_xor] = dp;
        }
    }

    std::cout << dp << std::endl;

    return 0;
}
