/**
 * 题目: 【GESP】C++一级练习 luogu-P1421, 小玉买文具
 * 题号: P1421
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1421/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量a和b来存储输入的元和角
    int a, b;
    // 从标准输入流中读取a和b的值
    cin >> a >> b;
    // 将角转换为分，并加上元转换为分的值
    b += a * 10;
    // 将总分数除以每只签字笔的价格（19分），得到可以买的签字笔数量
    b /= 19;
    // 输出可以买的签字笔数量，取整数部分
    cout << (int) b;
    // 程序返回0，表示执行成功
    return 0;
}
