/**
 * 题目: 【GESP】C++一级练习BCQM3052，鸡兔同笼
 * 题号: 3052
 * 归属: GESP1级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3052/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int x, y; // 声明 x: 头数, y: 脚数
    cin >> x >> y; // 输入总头数和总脚数
    int chicken, rabbit;
    // 穷举鸡的数量，从 0 一直尝试到 x
    for (int i = 0; i <= x; i++) {
        chicken = i; // 假设当前鸡的数量为 i
        rabbit = x - chicken; // 那么兔子的数量就是总头数减去鸡的数量
        // 检查头和脚的数量是否满足题意（鸡有 2 只脚，兔子有 4 只脚）
        if (chicken + rabbit == x && chicken * 2 + rabbit * 4 == y) {
            cout << chicken << " " << rabbit; // 输出符合条件的鸡和兔的数量
        }
    }
    return 0;
}
