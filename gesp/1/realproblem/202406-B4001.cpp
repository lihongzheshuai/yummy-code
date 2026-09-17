/**
 * 题目: 【GESP】C++一级真题(202406)luogu-B4001，立方数
 * 题号: B4001
 * 归属: GESP1级 (202406认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4001/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int n; // 定义变量n来存储输入的正整数
    cin >> n; // 从标准输入流中读取正整数n
    int u = 0; // 初始化计数器u为0，用于记录是否找到立方根
    for (int i = 1; i <= n; i++) { // 从1开始遍历到n
        if (i * i * i == n) { // 检查i是否是n的立方根
            u += 1; // 如果是，则计数器u加1
        } else {
            u += 0; // 如果不是，则计数器u不变
        }
    }
    if (u == 0) { // 如果计数器u为0，则n不是立方数
        cout << "No"; // 输出No
    } else { // 如果计数器u不为0，则n是立方数
        cout << "Yes"; // 输出Yes
    }
    return 0; // 程序返回0，表示执行成功
}
