/**
 * 题目: 【GESP】C++二级练习 luogu-B3700 [语言月赛202301] 九九乘方表
 * 题号: B3700
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3700/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    for (int i = 1; i <= n; i++) { // 从1到n遍历
        for (int j = 1; j <= i; j++) { // 从1到i遍历
            long long a = pow(i, j); // 计算i的j次方
            cout << i << " " << "^" << " " << j << " " << "=" << " " << a // 输出结果
                 << " ";
        }
        cout << endl; // 换行
    }
    return 0; // 退出程序
}
