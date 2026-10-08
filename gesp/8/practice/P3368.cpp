/**
 * 题目: 【GESP/CSP练习】GESP八级 / CSP-S 题解：luogu-P3368 【模板】树状数组 2
 * 题号: P3368
 * 归属: GESP八级 / CSP-S / 高级数据结构·差分树状数组模板题
 * 博客: https://www.coderli.com/gesp-8-luogu-p3368/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>

using namespace std;

// 最大序列长度
const int MAXN = 500005;

// 数列长度 n 与操作次数 m
int n, m;

// 树状数组存储数组，维护原数列的一阶差分序列 d[i]
// 采用 long long 类型防止多次修改累加导致数值溢出
long long tree[MAXN];

/**
 * 计算低位二进制权值 lowbit(x)
 * 返回 x 在二进制表示下最低位的 1 及其后所有 0 构成的数值
 * 利用计算机补码特性：-x = ~x + 1，因此 x & (-x) 即为最低位的二进制权值
 * @param x 正整数索引
 * @return 最低位二进制权值
 */
int lowbit(int x) {
    return x & (-x);
}

/**
 * 树状数组单点增量更新
 * 将差分序列中位置 x 处的权值增加 val
 * 沿树状数组向根部逐层跃迁，更新所有覆盖该位置的管辖区间节点
 * @param x 差分序列下标（1-indexed）
 * @param val 增加的增量值
 */
void update(int x, long long val) {
    for (; x <= n; x += lowbit(x)) {
        tree[x] += val;
    }
}

/**
 * 树状数组前缀和查询
 * 计算差分序列区间 [1, x] 的前缀和
 * 由一阶差分性质可知，差分序列的前缀和恰好还原为原序列位置 x 处的真实值
 * @param x 前缀终止下标（1-indexed）
 * @return 差分序列前缀和（即原序列位置 x 的当前数值）
 */
long long query_prefix(int x) {
    long long sum = 0;
    for (; x > 0; x -= lowbit(x)) {
        sum += tree[x];
    }
    return sum;
}

/**
 * 区间增量修改操作
 * 将原序列区间 [x, y] 内所有元素加上 k
 * 根据差分原理，原序列区间加操作等价于在差分序列中：
 * 位置 x 加上 k，位置 y + 1 减去 k
 * @param x 区间起始下标（1-indexed）
 * @param y 区间终止下标（1-indexed）
 * @param k 增加的数值
 */
void range_add(int x, int y, long long k) {
    update(x, k);
    if (y + 1 <= n) {
        update(y + 1, -k);
    }
}

int main() {
    cin >> n >> m;

    long long prev = 0;
    // 读入初始序列元素，直接差分后插入树状数组
    for (int i = 1; i <= n; ++i) {
        long long current;
        cin >> current;
        // 计算相邻差分值 d[i] = a[i] - a[i - 1] 并更新到树状数组中
        update(i, current - prev);
        prev = current;
    }

    // 处理 m 次操作指令
    for (int i = 0; i < m; ++i) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            range_add(x, y, k);
        } else if (opt == 2) {
            int x;
            cin >> x;
            cout << query_prefix(x) << "\n";
        }
    }

    return 0;
}
