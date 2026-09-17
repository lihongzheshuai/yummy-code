/**
 * 题目: 【GESP】C++二级练习 luogu-B3735 [信息与未来 2018] 圣诞树
 * 题号: B3735
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3735/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量n用于存储圣诞树的层数
    int n;
    // 从标准输入读取层数
    cin >> n;
    // 定义变量ans用于存储所需绳子的总段数
    int ans = 0;
    // 如果只有一层，不需要绳子
    if (n == 1) {
        ans = 0;
    } else {
        // 计算所需绳子总段数
        // 每层向下连接的绳子数：(2 + (n-1)*2)*(n-1)/2
        // 最后一层相邻星星之间的绳子数：(n-1)
        ans = (2 + (n - 1) * 2) * (n - 1) / 2 + (n - 1);
    }
    // 输出结果
    cout << ans;
    return 0;
}
