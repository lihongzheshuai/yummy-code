#include <algorithm>
#include <deque>
#include <iostream>

// 定义全局变量，数组稍微开大一点防止越界
// n 最大 10^6，开到 2*10^6 + 5
const int MAXN = 2000005;
int n;
int a[MAXN];
long long s[MAXN];  // 前缀和数组，使用 long long
                    // 防止溢出（虽然题目数据范围小，养成好习惯）
std::deque<int> q;  // 单调队列，存储的是下标

int main() {
    // 开启 IO 加速
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // 1. 读取输入
    if (!(std::cin >> n)) return 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        // 2. 破环成链：将数组复制一份拼接到后面，方便处理循环问题
        // 例如：1 2 3 -> 1 2 3 1 2
        a[i + n] = a[i];
    }

    // 3. 计算前缀和
    // 我们只需要处理到 2*n - 1 即可，足以覆盖所有长度为 n 的窗口
    for (int i = 1; i < 2 * n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int ans = 0;
    // 4. 使用单调队列维护滑动窗口的最小值
    // 我们需要检查每一个起点 k (1 <= k <= n)，对应的窗口是 [k, k+n-1]
    // 条件是：如果在窗口内所有前缀和的最小值 min(S[j]) >=
    // S[k-1]，则该方案可行。

    // 遍历所有的右端点 i，从 1 到 2*n - 1
    for (int i = 1; i < 2 * n; i++) {
        // 维护单调递增队列：如果队尾元素对应的前缀和 >=
        // 当前前缀和，则队尾元素不可能是最小值了，弹出
        while (!q.empty() && s[q.back()] >= s[i]) {
            q.pop_back();
        }
        q.push_back(i);  // 将当前下标加入队列

        // 如果队头下标已经超出了窗口范围 (窗口大小为 n)，弹出队头
        // 当前窗口右端点是 i，左端点应该是 i - n + 1
        // 如果队头下标 < 左端点，说明过期了
        if (i >= n) {
            int k = i - n + 1;  // 当前窗口对应的起点 k

            // 剔除过期的下标
            while (!q.empty() && q.front() < k) {
                q.pop_front();
            }

            // 此时 q.front() 就是当前窗口 [k, k+n-1] 内前缀和最小值的下标
            // 我们只关心起点 k 在 [1, n] 范围内的情景
            if (k <= n) {
                // 如果窗口内的最小前缀和 减去 还没开始前的累计和 (s[k-1]) 仍然
                // >= 0 说明从 k 开始一直累加，中间过程没有出现负数
                if (s[q.front()] - s[k - 1] >= 0) {
                    ans++;
                }
            }
        }
    }

    // 5. 输出结果
    std::cout << ans << std::endl;

    return 0;
}
