/**
 * 题目: 【GESP】C++一级练习 luogu-B2078, 含 k 个 3 的数
 * 题号: B2078
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2078/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream> // 引入输入输出流库
using namespace std;

int main() {
    long long m, k; // 定义两个长整型变量 m 和 k
    cin >> m >> k; // 从标准输入读取两个正整数 m 和 k
    int ans = 0; // 初始化计数器 ans，用于统计数字 3 的个数

    while (true) { // 无限循环，直到手动中断
        if (m % 10 == 3) { // 检查当前最低位是否为 3
            ans++; // 如果是 3，计数器加 1
        }
        m /= 10; // 去掉最低位，继续检查下一位
        if (m == 0) { // 如果 m 变为 0，说明所有位数都已检查完
            break; // 退出循环
        }
    }

    if (ans == k) { // 检查计数器 ans 是否等于 k
        cout << "YES"; // 如果相等，输出 "YES"
    } else {
        cout << "NO"; // 否则，输出 "NO"
    }
    return 0; // 返回 0，表示程序正常结束
}
