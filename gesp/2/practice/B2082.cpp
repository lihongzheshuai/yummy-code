/**
 * 题目: 【GESP】C++二级练习 luogu-b2082, 数字统计
 * 题号: B2082
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2082/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b; // 定义两个整数a和b
    cin >> a >> b; // 从输入流中读取a和b的值
    int ans = 0; // 初始化答案为0
    for (int i = a; i <= b; i++) { // 从a到b遍历每个数
        int d = i, num; // 将当前数i赋值给d，并定义一个临时变量num
        while (d != 0) { // 当d不为0时循环
            num = d % 10; // 取d的最后一位数字
            if (num == 2) { // 如果最后一位数字是2
                ans++; // 答案加1
            }
            d /= 10; // 将d除以10，去掉最后一位数字
        }
    }
    cout << ans; // 输出答案
    return 0;
}
