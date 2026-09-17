/**
 * 题目: 【GESP】C++三级真题 luogu-B4555 [GESP202606 三级] 加密
 * 题号: B4555
 * 归属: GESP3级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4555/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读入待加密的数字个数
    int n;
    std::cin >> n;
    // 读入待加密的数字，存入数组
    int a[20000];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    // 读入密码本，map[i] 表示数字 i 加密后变成 map[i]
    int map[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> map[i];
    }
    // 逐个替换并输出
    for (int i = 0; i < n; i++) {
        // 通过数组下标直接查表得到加密后的数字
        std::cout << map[a[i]];
        // 数字之间用空格分隔
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
