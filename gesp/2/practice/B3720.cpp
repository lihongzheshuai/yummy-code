/**
 * 题目: 【GESP】C++二级练习 luogu-B3720 [语言月赛202303] Out for Dinner B
 * 题号: B3720
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3720/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
using namespace std;
int main() {
    // 定义变量x存储消费金额
    long long x;
    cin >> x;
    // 定义变量a,b存储两道菜的名称
    char a, b;
    cin >> a >> b;
    // 定义变量price存储最终支付金额
    long long price;
    // 如果同时点了B和C，打6折
    if ((a == 'B' || b == 'B') && (a == 'C' || b == 'C')) {
        price = x / 10 * 6;
    }
    // 如果只点了C，打7折
    else if ((a == 'C' || b == 'C')) {
        price = x / 10 * 7;
    }
    // 如果只点了B，打8折
    else if ((a == 'B' || b == 'B')){
        price = x / 10 * 8;
    }
    // 其他情况不打折
    else {
        price = x;
    }
    // 输出最终支付金额
    cout << price;
    return 0;
}
