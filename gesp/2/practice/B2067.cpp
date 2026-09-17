/**
 * 题目: 【GESP】C++二级练习 luogu-b2067, 药房管理
 * 题号: B2067
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2067/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int m, n, ans = 0; // 定义变量m、n和ans，初始化ans为0
    cin >> m >> n; // 读取输入的m和n
    int n1; // 定义变量n1
    for (int i = 1; i <= n; i++) { // 遍历每个病人
        cin >> n1; // 读取当前病人希望取走的药品数量
        if (m - n1 >= 0) { // 如果当前药品总量足够满足当前病人的需求
            m -= n1; // 更新药品总量
        } else { // 如果当前药品总量不足以满足当前病人的需求
            ans++; // 计数增加，表示有一个病人没有取上药品
        }
    }
    cout << ans; // 输出没有取上药品的人数
    return 0;
}
