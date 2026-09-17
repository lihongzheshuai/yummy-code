/**
 * 题目: 【GESP】C++二级练习 luogu-b3670, [语言月赛202210] 玉桂狗
 * 题号: B3670
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3670/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, r; // 定义变量n和r
    cin >> n >> r; // 读取输入的n和r
    int k, p; // 定义变量k和p
    int max = 0; // 初始化变量max为0
    for (int i = 1; i <= n; i++) { // 遍历每只玉桂狗玩偶
        cin >> k >> p; // 读取当前玉桂狗玩偶的可爱度k和价格p
        if (k > max && p <= r) { // 如果当前玉桂狗玩偶的可爱度k大于max且价格p小于或等于某E的钱数r
            max = k; // 更新max的值为k
        }
    }
    cout << max; // 输出max的值，即某E能够买到的最可爱的玉桂狗玩偶的可爱度
    return 0;
}
