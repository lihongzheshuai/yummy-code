/**
 * 题目: 【GESP】C++二级练习 luogu-P5721 【深基4.例6】数字直角三角形
 * 题号: P5721
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p5721/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <bits/stdc++.h>
using namespace std;
int main() {
    // 声明变量n用于存储输入的行数
    int n;
    // 从标准输入读取n的值
    cin >> n;
    // count用于记录当前要打印的数字
    int count = 1;
    // 外层循环控制行数，从n行递减到1行
    for (int i = n; i >= 1; i--) {
        // 内层循环控制每行打印的数字个数
        for (int j = 1; j <= i; j++) {
            // 使用printf格式化输出两位数，不足两位补零
            printf("%02d", count);
            // 数字递增
            count++;
        }
        // 每行结束后换行
        cout << endl;
    }

    return 0;
}
