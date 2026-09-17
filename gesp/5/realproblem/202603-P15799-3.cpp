/**
 * 题目: 【GESP】C++五级真题 luogu-P15799, [GESP202603 五级] 找数
 * 题号: P15799
 * 归属: GESP5级 (202603认证真题)
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p15799/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 解除 cin/cout 与 stdio 的同步，加速输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> A(n);
    std::vector<int> B(m);

    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    // 第一步：把 A 和 B 都排序
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int ans = 0;
    int i = 0, j = 0; // 两个指针分别指向 A 和 B 的起点

    // 第二步：像拉拉链一样，两个指针同时向前推进
    while (i < n && j < m) {
        if (A[i] == B[j]) {
            // 两边相等，说明找到了一个共同元素
            ans++;
            i++; // 两个指针都往前走一步
            j++;
        } else if (A[i] < B[j]) {
            // A 当前的数比 B 小，说明 A 的这个数在 B 里不存在
            // 让 A 的指针往前走，去找更大的数来匹配
            i++;
        } else {
            // B 当前的数比 A 小，同理让 B 的指针往前走
            j++;
        }
    }

    std::cout << ans << "\n";
    return 0;
}
