/**
 * 题目: 【GESP】C++五、六级练习题 luogu-P1886 【模板】单调队列 / 滑动窗口
 * 题号: P1886
 * 归属: GESP5级
 * 博客: https://www.coderli.com/gesp-6-luogu-p1886/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 数据规模最大为 1000000
const int MAXN = 1000005;

int ary[MAXN];
// 单调队列中存储的是数组元素的下标索引
int q[MAXN];

int main() {
    // 提升 cin cout 的读写速度，防止在读入海量数据时卡常超时
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    // 依次读入 n 个元素
    for (int i = 0; i < n; ++i) {
        std::cin >> ary[i];
    }

    // ========== 1. 求解滑动窗口的最小值 ==========
    int head = 0; // 队首指针
    int tail = 0; // 队尾指针（指向下一个要插入的位置）

    for (int i = 0; i < n; ++i) {
        // 第一步：队首出队 (剔除过期元素)
        // 如果队列不空，并且队首记录的下标已经超出了滑动窗口的合法范围 [i-k+1, i]，则队首出队
        if (head < tail && q[head] <= i - k) {
            head++;
        }

        // 第二步：队尾入队 (维护单调递增性)
        // 如果队列不空，并且队尾元素的值大于或等于准备入队的新元素的值
        // 那么队尾元素就不可能成为以后的最小值，将其从队尾弹出，让位给更小的新元素
        while (head < tail && ary[q[tail - 1]] >= ary[i]) {
            tail--;
        }

        // 此时队尾没有比新元素更大的值了，将新元素的下标即可安全入队
        q[tail] = i;
        tail++;

        // 第三步：输出答案
        // 当索引 i 大于等于 k-1 时，说明第一个完整的窗口已经形成，以后每一次循环都要输出队首指代的最小值
        if (i >= k - 1) {
            std::cout << ary[q[head]] << " ";
        }
    }
    std::cout << "\n";

    // ========== 2. 求解滑动窗口的最大值 ==========
    // 重新初始化队列头尾指针，清空队列
    head = 0;
    tail = 0;

    for (int i = 0; i < n; ++i) {
        // 第一步：队首出队 (剔除过期元素)
        if (head < tail && q[head] <= i - k) {
            head++;
        }

        // 第二步：队尾入队 (维护单调递减性)
        // 求最大值时，需要淘汰队尾所有比新元素小(或相等)的元素，给更有潜力成为最大值的新元素腾出空间
        while (head < tail && ary[q[tail - 1]] <= ary[i]) {
            tail--;
        }

        // 淘汰完毕，新元素的下标从队尾入队
        q[tail] = i;
        tail++;

        // 第三步：输出答案
        if (i >= k - 1) {
            std::cout << ary[q[head]] << " ";
        }
    }
    std::cout << "\n";

    return 0;
}
