/**
 * 题目: 【GESP】C++三级练习 luogu-B3661, [语言月赛202209] 排排队
 * 题号: B3661
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3661/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;  // 读取数组长度
    cin >> n;
    int* input_array = new int[n];  // 动态分配数组空间
    for (int i = 0; i < n; i++) {
        cin >> input_array[i];  // 读取数组元素
    }
    // 打印奇数
    for (int i = 0; i < n; i++) {
        if (input_array[i] % 2 != 0) {
            cout << input_array[i] << " ";
        }
    }
    cout << endl;  // 换行，分隔奇数和偶数
    // 打印偶数
    for (int i = 0; i < n; i++) {
        if (input_array[i] % 2 == 0) {
            cout << input_array[i] << " ";
        }
    }
    return 0;
}
