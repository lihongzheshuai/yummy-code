/**
 * 题目: 【GESP】C++二级练习 luogu-B3721 [语言月赛202303] Stone Gambling S
 * 题号: B3721
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3721/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取测试用例数量
    int T;
    cin >> T;
    // 循环处理每个测试用例
    for (int i = 0; i < T; i++) {
        // 读取初始石头数量
        long long x, y;
        cin >> x >> y;
        // 使用临时变量存储当前状态
        long long tmp_x = x;
        long long tmp_y = y;
        // is_f为true表示当前是Farmer John的回合
        bool is_f = true;
        // 当双方都还有石头时继续游戏
        while (tmp_x != 0 && tmp_y != 0) {
            if (is_f) {
                // Farmer John的回合
                if (tmp_x < tmp_y) {
                    // 如果石头少于对方，拿一块
                    tmp_x += 1;
                } else {
                    // 否则扔掉一半
                    tmp_x /= 2;
                }
            } else {
                // Bessie的回合
                if (tmp_y < tmp_x) {
                    // 如果石头少于对方，拿一块
                    tmp_y += 1;
                } else {
                    // 否则扔掉一半
                    tmp_y /= 2;
                }
            }
            // 切换回合
            is_f = !is_f;
        }
        // 输出最终结果
        cout << tmp_x << " " << tmp_y << endl;
    }
    return 0;
}
