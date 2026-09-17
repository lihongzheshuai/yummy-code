/**
 * 题目: 【GESP】C++三级练习 luogu-t250431, 找元素
 * 题号: T250431
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-t250431/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int n, x; // 定义变量n, x
    cin >> n; // 读取输入的n
    int a[n]; // 定义数组a，大小为n
    for (int i = 0; i < n; i++) { // 循环读取n个整数到数组a
        cin >> a[i];
    }
    cin >> x; // 读取输入的整数x
    for (int i = n - 1; i >= 0; i--) { // 从数组a的末尾开始遍历，直到找到第一个等于x的元素
        if (a[i] == x) {
            cout << i + 1; // 输出找到的元素的位置
            break; // 找到后跳出循环
        }
    }
    return 0; // 返回0，表示程序正常结束
}
