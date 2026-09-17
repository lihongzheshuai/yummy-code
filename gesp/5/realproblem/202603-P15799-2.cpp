/**
 * 题目: 【GESP】C++五级真题 luogu-P15799, [GESP202603 五级] 找数
 * 题号: P15799
 * 归属: GESP5级 (202603认证真题)
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p15799/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <set>

int main() {
    // 解除 cin/cout 与 stdio 的同步，加速输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    // 用 set 存放数组 A 的所有元素
    // set 底层是红黑树，插入和查找的时间复杂度都是 O(log n)
    std::set<int> setA;

    // 读入数组 A，逐个插入到 set 中
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        setA.insert(x); // 插入时 set 会自动去重并排序
    }

    int ans = 0;

    // 读入数组 B，每读一个就去 set 里查一下有没有
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        // count() 返回元素在 set 中出现的次数（0 或 1）
        if (setA.count(x)) {
            ans++;
        }
    }

    std::cout << ans << "\n";
    return 0;
}
