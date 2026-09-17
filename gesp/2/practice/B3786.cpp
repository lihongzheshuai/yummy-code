/**
 * 题目: 【GESP】C++二级练习 luogu-B3786, [信息与未来 2023] 幸运数字
 * 题号: B3786
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3786/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b; // 定义变量a和b，用于存储输入的范围
    cin >> a >> b; // 从输入流中读取a和b的值
    int count = 0; // 初始化计数器，用于统计幸运数字的数量
    for (int i = a; i <= b; i++) { // 遍历从a到b的所有数字
        bool isOdd = true; // 初始化标志，用于标记当前数字是否为奇数
        int oddSum = 0; // 初始化奇数位数和
        int evenSum = 0; // 初始化偶数位数和
        int curNum = i; // 当前数字
        while (curNum != 0) { // 当当前数字不为0时，继续循环
            int digit = curNum % 10; // 获取当前数字的最后一位
            if (isOdd) {
                oddSum += digit; // 如果当前位是奇数位，则将数字加到奇数位数和中
            } else {
                evenSum += digit; // 如果当前位是偶数位，则将数字加到偶数位数和中
            }
            isOdd = !isOdd; // 切换标志，用于下一位的判断
            curNum /= 10; // 移除当前数字的最后一位
        }
        if (oddSum == evenSum) { // 如果奇数位数和与偶数位数和相等，则当前数字为幸运数字
            count++; // 增加计数器
        }
    }
    cout << count; // 输出计数器的值，即幸运数字的数量
    return 0;
}
