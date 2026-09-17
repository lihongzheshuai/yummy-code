/**
 * 题目: 【GESP】C++一级知识点研究，cout和printf性能差异分析
 * 题号: 
 * 归属: GESP1级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-knowledge-cout-printf/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << "\n";
    }
    return 0;
}
