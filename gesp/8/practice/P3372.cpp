/**
 * 题目: 【GESP/CSP练习】GESP八级 / CSP-S 题解：luogu-P3372 【模板】线段树 1
 * 题号: P3372
 * 归属: GESP八级 / CSP-S / 高级数据结构·线段树区间加与Lazy标记维护
 * 博客: https://www.coderli.com/gesp-8-luogu-p3372/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>

using namespace std;

// 最大序列长度
const int MAXN = 100005;

// 数列长度 n 与操作次数 m
int n, m;

// 原始数列数组
long long a[MAXN];

// 线段树节点维护的区间和数组，空间需开辟原数组的 4 倍
long long tree[MAXN << 2];

// 延迟标记（Lazy Tag）数组，记录子树区间尚未下传的区间增量累加值
long long lazy[MAXN << 2];

/**
 * 向上更新节点区间和信息 (Push Up)
 * 父节点的区间和等于左子节点与右子节点的区间和之和
 * @param p 当前线段树节点编号
 */
void push_up(int p) {
    tree[p] = tree[p << 1] + tree[(p << 1) | 1];
}

/**
 * 向下传递延迟标记 (Push Down)
 * 当需要访问或修改子节点时，将当前节点的延迟增量分配给左右子树
 * 并更新左右子树维护的区间和数值，随后清空当前节点的延迟标记
 * @param p 当前线段树节点编号
 * @param l 当前节点管辖区间的左端点
 * @param r 当前节点管辖区间的右端点
 */
void push_down(int p, int l, int r) {
    if (lazy[p] != 0) {
        int mid = l + ((r - l) >> 1);
        int left_child = p << 1;
        int right_child = (p << 1) | 1;

        // 下传增量给左子节点，左子区间长度为 (mid - l + 1)
        lazy[left_child] += lazy[p];
        tree[left_child] += lazy[p] * (mid - l + 1);

        // 下传增量给右子节点，右子区间长度为 (r - mid)
        lazy[right_child] += lazy[p];
        tree[right_child] += lazy[p] * (r - mid);

        // 当前节点的延迟标记已成功分发，归零重置
        lazy[p] = 0;
    }
}

/**
 * 递归构建线段树 (Build)
 * 自底向上初始化线段树各节点的管辖区间和
 * @param p 当前线段树节点编号
 * @param l 当前节点管辖区间的左端点
 * @param r 当前节点管辖区间的右端点
 */
void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        // 叶子节点，直接赋值为原数组第 l 个元素
        tree[p] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(p << 1, l, mid);
    build((p << 1) | 1, mid + 1, r);
    push_up(p);
}

/**
 * 区间增量修改操作 (Range Update)
 * 将区间 [ql, qr] 内每一个元素均加上增量 val
 * @param p 当前线段树节点编号
 * @param l 当前节点管辖区间的左端点
 * @param r 当前节点管辖区间的右端点
 * @param ql 目标修改区间的左端点
 * @param qr 目标修改区间的右端点
 * @param val 增加的增量数值
 */
void update_range(int p, int l, int r, int ql, int qr, long long val) {
    // 当前节点区间被目标修改区间完全覆盖
    if (ql <= l && r <= qr) {
        tree[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    // 尚未完全覆盖，需要访问子区间，先下传延迟标记
    push_down(p, l, r);
    int mid = l + ((r - l) >> 1);
    if (ql <= mid) {
        update_range(p << 1, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        update_range((p << 1) | 1, mid + 1, r, ql, qr, val);
    }
    // 子区间更新后，重新汇总当前节点的区间和
    push_up(p);
}

/**
 * 区间求和查询操作 (Range Query)
 * 查询目标区间 [ql, qr] 内所有元素的累加和
 * @param p 当前线段树节点编号
 * @param l 当前节点管辖区间的左端点
 * @param r 当前节点管辖区间的右端点
 * @param ql 目标查询区间的左端点
 * @param qr 目标查询区间的右端点
 * @return 目标区间的元素累加和
 */
long long query_range(int p, int l, int r, int ql, int qr) {
    // 当前节点区间被目标查询区间完全覆盖，直接返回该节点的区间和
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    // 尚未完全覆盖，先下传延迟标记
    push_down(p, l, r);
    int mid = l + ((r - l) >> 1);
    long long total = 0;
    if (ql <= mid) {
        total += query_range(p << 1, l, mid, ql, qr);
    }
    if (qr > mid) {
        total += query_range((p << 1) | 1, mid + 1, r, ql, qr);
    }
    return total;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; ++i) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            update_range(1, 1, n, x, y, k);
        } else if (opt == 2) {
            int x, y;
            cin >> x >> y;
            cout << query_range(1, 1, n, x, y) << "\n";
        }
    }

    return 0;
}
