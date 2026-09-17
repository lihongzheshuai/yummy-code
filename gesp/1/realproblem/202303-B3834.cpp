/**
 * 题目: 【GESP】C++一级真题练习(202303)luogu-B3834，长方形面积
 * 题号: B3834
 * 归属: GESP1级 (202303认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3834/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义变量b用于存储输入的长方形面积
    int b;
    // 从标准输入读取面积值
    cin >> b;

    // 定义计数器a，用于记录可能的长方形数量
    int a = 0;

    // 遍历从1到sqrt(b)的所有可能的宽度
    // i * i <= b 等价于 i <= sqrt(b)
    for (int i = 1; i * i <= b; i++) {
        // 如果b能被i整除，说明找到了一组有效的长和宽
        if (b % i == 0) {
            // 计数器加1
            a += 1;
        }
    }

    // 输出结果：可能的长方形数量
    cout << a;
}
