/**
 * 题目: 【GESP】C++二级真题 luogu-b4002, [GESP202406 二级] 平方之和
 * 题号: B4002
 * 归属: GESP2级 (202406认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4002/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 输入的正整数数量
    cin >> n; // 读取输入的正整数数量
    int a1; // 每个正整数
    for (int i = 1; i <= n; i++) { // 遍历每个正整数
        cin >> a1; // 读取每个正整数
        bool flag = false; // 标志是否找到满足条件的x和y
        for (int k = 1; k * k < a1; k++) { // 遍历可能的x值
            double r = sqrt(a1 - k * k); // 计算可能的y值
            int d = (int)r; // 将y值转换为整数
            if (d * d + k * k == a1 && d != 0) { // 判断是否满足条件
                flag = true; // 如果满足条件，则标志为true
                break; // 并退出循环
            }
        }
        if (flag) { // 如果找到满足条件的x和y
            cout << "Yes" << endl; // 输出Yes
        } else { // 如果没有找到满足条件的x和y
            cout << "No" << endl; // 输出No
        }
    }
    return 0;
}
