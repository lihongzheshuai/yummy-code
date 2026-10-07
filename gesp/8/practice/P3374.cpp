/**
 * 题目: 【GESP/CSP练习】GESP八级 / CSP-S 题解：luogu-P3374 【模板】树状数组 1
 * 题号: P3374
 * 归属: GESP八级 / CSP-S / 高级数据结构·树状数组模板题
 * 博客: https://www.coderli.com/gesp-8-luogu-p3374/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

// 最大元素个数
const int MAXN = 500005;

// 数列长度 n 与操作次数 m
int n, m;

// 树状数组存储数组，采用 long long 防止累加和溢出
long long tree[MAXN];

/**
 * 计算低位二进制位 lowbit(x)
 * 返回 x 在二进制表示下最低位的 1 及其后所有 0 构成的数值
 * 利用补码性质：-x = ~x + 1，因此 x & (-x) 即为最低位的二进制权值
 * @param x 正整数索引
 * @return 最低位二进制权值
 */
int lowbit(int x) {
    return x & (-x);
}

/**
 * 树状数组单点增加操作
 * 将序列中第 x 个元素的值增加 val
 * 沿树状数组向根部跃迁，逐层更新包含该位置的所有树状数组区间节点
 * @param x 目标位置下标（1-indexed）
 * @param val 增加的增量值
 */
void update(int x, long long val) {
    for (; x <= n; x += lowbit(x)) {
        tree[x] += val;
    }
}

/**
 * 树状数组前缀和查询操作
 * 计算原数组区间 [1, x] 内所有元素的累加和
 * 沿树状数组向左折跃，累加每个由 lowbit 覆盖的不相交子区间权值
 * @param x 前缀终止下标（1-indexed）
 * @return 前缀区间 [1, x] 的元素和
 */
long long query_prefix(int x) {
    long long sum = 0;
    for (; x > 0; x -= lowbit(x)) {
        sum += tree[x];
    }
    return sum;
}

/**
 * 树状数组区间和查询操作
 * 利用前缀和容斥原理求闭区间 [x, y] 内所有元素的和
 * 区间和等于前缀和 S(y) 减去前缀和 S(x - 1)
 * @param x 区间起始下标（1-indexed）
 * @param y 区间终止下标（1-indexed）
 * @return 区间 [x, y] 的元素和
 */
long long query_range(int x, int y) {
    return query_prefix(y) - query_prefix(x - 1);
}

int main() {
    cin >> n >> m;

    // 读入初始序列元素并构建树状数组
    for (int i = 1; i <= n; ++i) {
        long long val;
        cin >> val;
        update(i, val);
    }

    // 处理 m 次操作
    for (int i = 0; i < m; ++i) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x;
            long long k;
            cin >> x >> k;
            update(x, k);
        } else if (opt == 2) {
            int x, y;
            cin >> x >> y;
            cout << query_range(x, y) << "\n";
        }
    }

    return 0;
}
