#include <iostream>

int l[100005];
int r[100005];
bool deleted[100005];
int main() {
    int N;
    std::cin >> N;
    l[1] = 0;
    r[1] = 0;
    int head = 1;
    for (int i = 2; i <= N; i++) {
        int k, p;
        std::cin >> k >> p;

        if (p == 0) {
            // 将 i 插入到 k 的左边
            if (l[k] == 0) {
                head = i;  // 如果 k 原来是头，即 l[k] == 0，既然 i 到了 k
                           // 左边，i 变成新头
            }
            // 链接 i 和 k 的左邻居（如果存在）
            if (l[k] != 0) {
                r[l[k]] = i;  // k 的左邻居的右边现在是 i
            }
            l[i] = l[k];  // i 的左边是 k 原来的左边

            // 链接 i 和 k
            l[k] = i;  // k 的左边现在是 i
            r[i] = k;  // i 的右边现在是 k

        } else {
            // 将 i 插入到 k 的右边
            if (r[k] != 0) {
                l[r[k]] = i;  // k 的右邻居的左边现在是 i
            }
            r[i] = r[k];  // i 的右边是 k 原来的右边

            // 链接 k 和 i
            l[i] = k;  // i 的左边是 k
            r[k] = i;  // k 的右边是 i
        }
    }

    int M;
    std::cin >> M;
    // 使用 deleted 数组标记是否已删除，避免重复处理

    while (M--) {
        int x;
        std::cin >> x;
        if (deleted[x]) {
            continue;  // 如果 x 已经不在队列中，忽略
        }
        deleted[x] = true;

        // 处理头节点情况
        if (head == x) {
            head = r[x];  // 头节点后移
        }

        // 逻辑修复：更新邻居指针
        // 1. 如果 x 有左邻居，让左邻居的右指针指向 x 的右邻居
        if (l[x] != 0) {
            r[l[x]] = r[x];
        }
        // 2. 如果 x 有右邻居，让右邻居的左指针指向 x 的左邻居
        if (r[x] != 0) {
            l[r[x]] = l[x];
        }

        // 清空 x 的指针（可选，但为了调试清晰保留）
        l[x] = 0;
        r[x] = 0;
    }

    // 输出队列
    int curr = head;
    while (curr != 0) {
        std::cout << curr << ' ';
        curr = r[curr];
    }

    return 0;
}