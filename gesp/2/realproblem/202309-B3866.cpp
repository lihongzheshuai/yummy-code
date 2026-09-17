/**
 * 题目: 【GESP】C++二级真题 luogu-b3866, [GESP202309 二级] 数字黑洞
 * 题号: B3866
 * 归属: GESP2级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3866/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 读取输入的n
    int count = 0; // 初始化计数为0
    while (true) {
        if (n == 495) { // 如果n等于495，则跳出循环
            cout << count; // 输出计数
            break;
        }
        int n1 = n % 10; // 获取n的个位数
        int n2 = n / 10 % 10; // 获取n的十位数
        int n3 = n / 10 / 10; // 获取n的百位数

        int n_max = max(n1, max(n2, n3)); // 找到最大数
        int n_min = min(n1, min(n2, n3)); // 找到最小数
        int n_mid = n1 + n2 + n3 - n_max - n_min; // 计算中间数

        n = n_max * 100 + n_mid * 10 + n_min - n_min * 100 - n_mid * 10 - n_max; // 更新n的值
        count++; // 计数增加
    }

    return 0;
}
