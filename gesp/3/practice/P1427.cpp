/**
 * 题目: 【GESP】C++三级练习 luogu-P1427, 小鱼的数字游戏
 * 题号: P1427
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1427/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream> // 引入输入输出流库
using namespace std;

int main() {
    int* a = new int[100]; // 动态分配一个大小为100的整数数组
    int last_index = 0; // 记录最后一个有效输入的索引

    // 无限循环，直到输入0为止
    for (int i = 0;; i++) {
        cin >> a[i]; // 从标准输入读取整数
        if (a[i] == 0) { // 检查输入是否为0
            last_index = i - 1; // 更新最后一个有效输入的索引
            break; // 退出循环
        }
    }
    // 从最后一个有效输入的索引开始，倒序输出数组中的整数
    for (int i = last_index; i >= 0; i--) {
        cout << a[i] << " "; // 输出当前整数并加上空格
    }

    return 0; // 程序结束
}
