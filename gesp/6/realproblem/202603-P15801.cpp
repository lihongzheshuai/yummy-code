/**
 * 题目: 【GESP】C++六级真题 luogu-P15801, [GESP202603 六级] 完全二叉树
 * 题号: P15801
 * 归属: GESP6级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p15801/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

const int MAXN = 100005;
int l_child[MAXN], r_child[MAXN]; // 左右儿子
int height_val[MAXN]; // 子树高度
int sz[MAXN]; // 子树结点数
bool isCBT[MAXN]; // 是否为完全二叉树
int ans = 0; // 完全二叉树计数

// DFS 后序遍历
void dfs(int u) {
    // 空结点，直接返回
    if (u == 0) {
        return;
    }

    // 递归处理左右子树
    dfs(l_child[u]);
    dfs(r_child[u]);

    int L = l_child[u];
    int R = r_child[u];

    // 计算高度和结点数
    height_val[u] = std::max(height_val[L], height_val[R]) + 1;
    sz[u] = sz[L] + sz[R] + 1;

    // 判断是否为完全二叉树
    isCBT[u] = false;

    if (L == 0 && R == 0) {
        // 情况1：叶结点，一定是完全二叉树
        isCBT[u] = true;
    } else if (L != 0 && R == 0) {
        // 情况2：只有左儿子，左儿子必须是叶结点
        if (height_val[L] == 1) {
            isCBT[u] = true;
        }
    } else if (L != 0 && R != 0) {
        // 情况3：左右儿子都存在
        int hl = height_val[L], hr = height_val[R];
        if (hl == hr) {
            // 左右等高：左子树必须是满二叉树，右子树是完全二叉树
            // 满二叉树结点数 = 2^h - 1
            if (sz[L] == (1 << hl) - 1 && isCBT[L] && isCBT[R]) {
                isCBT[u] = true;
            }
        } else if (hl == hr + 1) {
            // 左比右高1：右子树必须是满二叉树，左子树是完全二叉树
            if (sz[R] == (1 << hr) - 1 && isCBT[L] && isCBT[R]) {
                isCBT[u] = true;
            }
        }
        // 其他高度差情况，不是完全二叉树
    }
    // 只有右儿子没有左儿子的情况，不是完全二叉树

    if (isCBT[u]) {
        ans++;
    }
}

int main() {
    // 优化输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // 初始化空结点的高度和结点数为 0
    height_val[0] = 0;
    sz[0] = 0;

    for (int i = 1; i <= n; i++) {
        std::cin >> l_child[i] >> r_child[i];
    }

    // 从根结点（编号1）开始 DFS
    dfs(1);

    std::cout << ans << "\n";

    return 0;
}
