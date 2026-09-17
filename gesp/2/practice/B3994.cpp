/**
 * 题目: 【GESP】C++二级模拟 luogu-b3994, [GESP 二级模拟] 周长与面积计算
 * 题号: B3994
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3994/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    long long n; // 定义一个长整型变量n
    cin >> n; // 从标准输入流中读取n的值
    long long s = 0, l = 0; // 定义两个长整型变量s和l，初始化为0
    for (long long i = n; i >= 1; i--) { // 从n开始循环，每次递减1
        s += i * i; // 计算i的平方并加到s上
    }
    l = (1 + n) * n; // 计算l的值
    l += n * 2; // 计算l的值
    cout << l << endl; // 输出l的值并换行
    cout << s; // 输出s的值
    return 0; // 返回0，表示程序正常结束
}
