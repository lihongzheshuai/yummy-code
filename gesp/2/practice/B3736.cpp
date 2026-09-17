/**
 * 题目: 【GESP】C++二级练习 luogu-B3736 [信息与未来 2018] 最大公约数
 * 题号: B3736
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3736/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    // 声明三个整数变量用于存储输入的数字
    int x, y, z;
    // 从标准输入读取三个数字
    cin >> x >> y >> z;
    // 找出三个数字中的最小值，因为最大公约数不会超过最小的数
    int m = min(x, min(y, z));
    // 初始化答案变量
    int ans = 0;
    // 从最小值开始向下遍历，找到第一个能同时整除三个数的数
    for (int i = m; i >= 1; i--) {
        // 判断i是否能同时整除x、y、z
        if (x % i == 0 && y % i == 0 && z % i == 0) {
            // 找到最大公约数，赋值给ans
            ans = i;
            // 找到后立即退出循环
            break;
        }
    }
    // 输出最大公约数
    cout << ans;
    // 程序正常结束
    return 0;
}
