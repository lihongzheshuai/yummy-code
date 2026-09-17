/**
 * 题目: 【GESP】C++二级练习 luogu-b2081, 与 7 无关的数
 * 题号: B2081
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2081/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    int ans = 0; // 初始化答案变量
    for (int i = 1; i <= n; i++) { // 从1到n遍历所有数
        int d = i, num; // 初始化变量d为i，num用于存储每一位数字
        bool flag = false; // 初始化标志变量，用于判断i是否与7无关
        if (i % 7 == 0) { // 如果i能被7整除，则i与7有关
            flag = true;
            continue; // 跳过当前循环，继续下一个数
        }
        while (d != 0) { // 循环直到d变为0
            num = d % 10; // 获取d的最后一位数字
            if (num == 7) { // 如果最后一位数字是7，则i与7有关
                flag = true;
                break; // 跳出循环
            }
            d /= 10; // 移除d的最后一位数字
        }
        if (!flag) { // 如果i与7无关
            ans += i * i; // 将i的平方加到答案中
        }
    }
    cout << ans; // 输出答案
    return 0;
}
