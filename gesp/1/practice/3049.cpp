/**
 * 题目: 【GESP】C++一级练习BCQM3049，细胞分裂
 * 题号: 3049
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3049/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int a = 1; // 初始状态，有1个细胞

    // 循环5次，模拟5次细胞分裂的过程
    for (int i = 0; i < 5; i++) {
        a *= 2; // 每次分裂，细胞数量变为原来的2倍（即原来的数量乘以2）
    }

    // 输出第5次分裂后的细胞总数
    cout << a << endl;
    return 0;
}
