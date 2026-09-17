/**
 * 题目: 【NOIP】1999真题解析 luogu-P1014 Cantor 表 | GESP三、四级以上可练习
 * 题号: P1014
 * 归属: GESP4级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/noi-p-1999-luogu-p1014/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int k = 1; // k 表示当前所在的第几条对角线

    // 利用减法定位 n 属于哪一条对角线
    // 每次减去当前对角线上的元素数量 k
    while (n > k) {
        n -= k;
        k++;
    }

    // 循环结束后，变量 k 就是第 N 项所在的对角线编号
    // 而此时的剩余值 n，即为元素在这条对角线上的顺序编号

    if (k % 2 == 0) {
        // 如果是偶数对角线，顺序是从右上到左下移动
        // 行号从小到大（等于此时的排位 n），列号从大到小
        // 根据 行+列 = k+1 的规律：
        std::cout << n << "/" << k + 1 - n << std::endl;
    } else {
        // 如果是奇数对角线，顺序是从左下到右上移动
        // 列号从小到大（等于此时的排位 n），行号从大到小
        std::cout << k + 1 - n << "/" << n << std::endl;
    }

    return 0;
}
