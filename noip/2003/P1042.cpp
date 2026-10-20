/**
 * Problem: luogu-P1042 [NOIP 2003 普及组] 乒乓球
 * Algorithm: 字符串存储与多赛制状态机模拟 (String Storage & Multi-Rule Simulation)
 * Standard: C++11 (CCF GESP 五级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/noip-2003-luogu-p1042/
 * Author: OneCoder
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 存储截至字符 'E' 之前的所有比赛胜负记录（'W' 或 'L'）
string records = "";

/**
 * 模拟并输出指定分制 target（11 分制或 21 分制）下的所有局比分
 * @param target 获胜所需的基础分数（11 或 21）
 */
void simulate(int target) {
    int w = 0; // 华华当前局的得分
    int l = 0; // 对手当前局的得分

    // 逐球遍历比赛记录
    for (size_t i = 0; i < records.length(); ++i) {
        if (records[i] == 'W') {
            w++;
        } else if (records[i] == 'L') {
            l++;
        }

        // 一局结束的判定条件：
        // 1. 至少有一方得分达到或超过 target（w >= target 或 l >= target）
        // 2. 双方分差的绝对值大于或等于 2（abs(w - l) >= 2）
        if ((w >= target || l >= target) && abs(w - l) >= 2) {
            cout << w << ":" << l << "\n";
            // 当一局比赛结束后，下一局立刻开始，双方比分清零
            w = 0;
            l = 0;
        }
    }

    // 关键边界：截至记录末尾，正在进行中的这一局（哪怕刚开局比分为 0:0）也必须输出
    cout << w << ":" << l << "\n";
}

int main() {
    char ch;
    // 逐字符读取输入（cin >> ch 会自动跳过空格和换行符）
    // 遇到比赛结束标志 'E' 时立即停止读取，忽略 'E' 之后的全部内容
    while (cin >> ch && ch != 'E') {
        if (ch == 'W' || ch == 'L') {
            records += ch;
        }
    }

    // 第一部分：输出 11 分制下的比赛结果
    simulate(11);

    // 两部分之间由一个空行分隔
    cout << "\n";

    // 第二部分：输出 21 分制下的比赛结果
    simulate(21);

    return 0;
}
