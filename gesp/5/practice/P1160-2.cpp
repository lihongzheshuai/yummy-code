/**
 * 题目: 【GESP】C++五级练习题 luogu-P1160 队列安排
 * 题号: P1160
 * 归属: GESP5级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1160/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 使用结构体定义节点
struct Node {
    int l, r;      // 左、右邻居的编号
    bool deleted;  // 删除标记
} nodes[100005];

int main() {
    int N;
    std::cin >> N;

    // 初始化 1 号节点
    nodes[1].l = 0;
    nodes[1].r = 0;
    nodes[1].deleted = false;

    int head = 1; // 维护队头

    for (int i = 2; i <= N; i++) {
        int k, p;
        std::cin >> k >> p;
        nodes[i].deleted = false;

        if (p == 0) {
            // 将 i 插入到 k 的左边
            // 1. 设置 i 的左右指针
            nodes[i].l = nodes[k].l;
            nodes[i].r = k;

            // 2. 更新 k 左邻居的右指针 (如果存在)
            if (nodes[k].l != 0) {
                nodes[nodes[k].l].r = i;
            } else {
                // k 原本是队头，现在 i 插在 k 左边，i 变成新队头
                head = i;
            }

            // 3. 更新 k 的左指针
            nodes[k].l = i;

        } else {
            // 将 i 插入到 k 的右边
            // 1. 设置 i 的左右指针
            nodes[i].l = k;
            nodes[i].r = nodes[k].r;

            // 2. 更新 k 右邻居的左指针 (如果存在)
            if (nodes[k].r != 0) {
                nodes[nodes[k].r].l = i;
            }

            // 3. 更新 k 的右指针
            nodes[k].r = i;
        }
    }

    int M;
    std::cin >> M;
    while (M--) {
        int x;
        std::cin >> x;
        if (nodes[x].deleted) {
            continue;
        }
        nodes[x].deleted = true;

        // 如果删除的是头节点，更新头节点
        if (head == x) {
            head = nodes[x].r;
        }

        // 链接 x 的左邻居和右邻居
        if (nodes[x].l != 0) {
            nodes[nodes[x].l].r = nodes[x].r;
        }
        if (nodes[x].r != 0) {
            nodes[nodes[x].r].l = nodes[x].l;
        }
    }

    // 从头遍历输出
    int curr = head;
    while (curr != 0) {
        std::cout << curr << " ";
        curr = nodes[curr].r;
    }

    return 0;
}
