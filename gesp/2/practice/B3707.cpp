/**
 * 题目: 【GESP】C++二级练习 luogu-B3707 [语言月赛202302] 风神瞳
 * 题号: B3707
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3707/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int p, x, y, g, h;  // 定义变量：棋子类型p，当前坐标(x,y)，目标坐标(g,h)
    cin >> p >> x >> y >> g >> h;  // 输入棋子类型和坐标

    if (p == 1) {  // 处理车的情况
        if (x == g || y == h) {  // 判断是否在同一行或同一列
            cout << "Yes";  // 可以吃掉
        } else {
            cout << "No";  // 不能吃掉
        }
    } else if (p == 2) {  // 处理炮的情况
        cout << "No";  // 直接输出不能吃掉
    } else if (p == 3) {  // 处理马的情况
        // 判断是否在马的8个可能位置
        if ((g == x + 2 && h == y + 1) || (g == x + 2 && h == y - 2) ||
            (g == x - 2 && h == y + 1) || (g == x - 2 && h == y - 1) ||
            (g == x + 1 && h == y + 2) || (g == x + 1 && h == y - 2) ||
            (g == x - 1 && h == y + 2) || (g == x - 1 && h == y - 2)) {
            cout << "Yes";  // 可以吃掉
        } else {
            cout << "No";  // 不能吃掉
        }
    } else {  // 处理象的情况
        // 判断是否在象的4个可能位置
        if ((g == x + 2 && h == y + 2) || (g == x + 2 && h == y - 2) ||
            (g == x - 2 && h == y + 2) || (g == x - 2 && h == y - 2)) {
            cout << "Yes";  // 可以吃掉
        } else {
            cout << "No";  // 不能吃掉
        }
    }
    return 0;  // 程序正常结束
}
