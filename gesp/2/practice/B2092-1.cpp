/**
 * 题目: 【GESP】C++二级练习 luogu-B2092, 开关灯
 * 题号: B2092
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2092/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 输入的灯的数量
    cin >> n;
    int arr[n]; // 创建一个大小为n的数组，用于存储每个灯的状态
    for (int i = 0; i < n; i++) {
        arr[i] = false; // 初始化所有灯为关着的状态
    }
    for (int i = 1; i < n; i += 2) {
        arr[i] = true; // 将2的倍数编号的灯打开
    }

    for (int i = 3; i <= n; i++) {
        for (int j = i - 1; j < n; j += i) {
            arr[j] = !arr[j]; // 根据每个数i，切换编号为i的倍数的灯的开关
        }
    }
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            cout << i + 1 << " "; // 输出关着的灯的编号
        }
    }
    return 0;
}
