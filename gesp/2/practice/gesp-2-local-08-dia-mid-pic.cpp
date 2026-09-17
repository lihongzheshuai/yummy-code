/**
 * 题目: 【GESP】C++二级练习 图形输出练习08-菱形（十字）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-08-dia-mid-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n用于存储输入的大小
    int n;
    // 从标准输入读取n的值
    cin >> n;
    // 计算中间位置索引
    int mid_idx = (n + 1) / 2;
    // 外层循环控制行数
    for (int i = 1; i <= n; i++) {
        // 内层循环控制每行的字符输出
        for (int j = 1; j <= n; j++) {
            // 处理十字交叉的中心线
            if (i == mid_idx || j == mid_idx) {
                cout << "*";
            }
            // 处理上半部分的图案
            else if (i < mid_idx) {
                // 根据位置计算是否输出星号
                if (j == mid_idx - i + 1 || j == mid_idx + i - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            // 处理下半部分的图案
            else {
                // 根据位置计算是否输出星号
                if (j == i -mid_idx + 1 || j == n - i + mid_idx) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    return 0;
}
