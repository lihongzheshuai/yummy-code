#include <deque>
#include <iostream>

// 数组大小设置为 2*10^6，因为 n 最大为 10^6，且需要断环成链开两倍空间
int a[2000005];
int pre[2000005];  // 前缀和数组

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        // 断环成链：将原数组复制一份接在后面，模拟环状结构
        // 这样处理后，从任意 k 开始的长度为 n 的序列在数组中就是连续的一段
        a[i + n] = a[i];
    }

    // 计算前缀和
    // pre[i] 表示序列前 i 项的和。
    // 注意这里计算到了 2*n - 1，覆盖了所有可能的起始位置延展出的 n 长度序列
    for (int i = 1; i < 2 * n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    int count = 0;
    std::deque<int> q;  // 单调队列，用于维护当前滑动窗口内的最小前缀和的下标

    // 遍历所有可能的结束位置 i
    for (int i = 1; i < 2 * n; i++) {
        // 维护单调递增队列：
        // 如果新元素 pre[i] 比队尾元素更小（或相等），
        // 那么队尾元素就不可能是当前或未来窗口的最小值了，可以直接弹出
        while (!q.empty() && pre[q.back()] >= pre[i]) {
            q.pop_back();
        }
        q.push_back(i);

        // 如果 i >= n，说明窗口大小已经达到了 n，可以开始判断是否有解
        // 此时窗口对应的原序列起始位置 k = i - n + 1
        if (i >= n) {
            int k = i - n + 1;

            // 检查队头元素是否已滑出窗口 [k, i]
            // 如果队头下标小于 k，说明该最小值不在当前考虑的区间内，弹出
            if (!q.empty() && q.front() < k) {
                q.pop_front();
            }

            // 我们只关心 k 在 1 到 n 之间的情况
            if (k <= n) {
                // 核心判断逻辑：
                // 如果从 k 开始每一步累加都不小于 0，等价于
                // 区间 [k, k+n-1] 内的所有前缀和 pre[j] 减去 pre[k-1] 都 >= 0
                // 即：min(pre[k...i]) - pre[k-1] >= 0
                // q.front() 保存了区间 [k, i] 内最小前缀和的下标
                if (pre[q.front()] - pre[k - 1] >= 0) {
                    count++;
                }
            }
        }
    }

    std::cout << count;
    return 0;
}
