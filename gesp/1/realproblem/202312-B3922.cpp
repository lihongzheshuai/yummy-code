/**
 * 题目: 【GESP】C++一级真题练习(202312)luogu-B3922，小杨报数
 * 题号: B3922
 * 归属: GESP1级 (202312认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3922/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int N, M;  // N为报数上限，M为需要跳过的倍数
    cin >> N >> M;  // 输入N和M

    // 遍历从1到N的所有数字
    for (int i = 1; i <= N; i++) {
        // 判断当前数字i是否不是M的倍数
        if (i % M != 0) {
            cout << i << endl;  // 如果不是M的倍数，则输出该数字
        }
        // 如果是M的倍数，则跳过不输出
    }

    return 0;
}
