/**
 * 题目: 【GESP】C++五级真题 luogu-P17010 [GESP202606 五级] 排排坐
 * 题号: P17010
 * 归属: GESP5级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-p17010/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int a[1005];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // 降序排列：让最大的数字排在最左边，获得最大的贡献系数
    std::sort(a, a + n, std::greater<int>());

    // 计算糖果总量
    // 排序后 a[0] 是最大值，位于第 1 个位置，贡献系数为 n
    // a[1] 位于第 2 个位置，贡献系数为 n - 1
    // a[i] 位于第 i+1 个位置，贡献系数为 n - i
    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (long long)(n - i) * a[i];
    }

    std::cout << total << std::endl;
    return 0;
}
