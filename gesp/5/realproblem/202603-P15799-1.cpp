/**
 * 题目: 【GESP】C++五级真题 luogu-P15799, [GESP202603 五级] 找数
 * 题号: P15799
 * 归属: GESP5级 (202603认证真题)
 * 解法: 解法 1 / 共 3 种解法
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

    // 分别用 vector 存放数组 A 和数组 B
    std::vector<int> A(n);
    std::vector<int> B(m);

    // 读入数组 A
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    // 读入数组 B
    for (int i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    // 第一步：将数组 A 排序，为二分查找打好基础
    std::sort(A.begin(), A.end());

    int ans = 0;

    // 第二步：遍历数组 B 的每个元素，用二分查找去排好序的 A 里"点名"
    for (int i = 0; i < m; i++) {
        // binary_search 是 C++ 标准库自带的二分查找函数
        // 在已排序的 A 中查找 B[i]，找到返回 true
        if (std::binary_search(A.begin(), A.end(), B[i])) {
            ans++;
        }
    }

    std::cout << ans << "\n";
    return 0;
}
