/**
 * Problem: luogu-P1157 组合的输出
 * Algorithm: 递归枚举与可行性剪枝 (Recursive Combination Enumeration)
 * Standard: C++11 (CCF GESP 四级 / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>
#include <iomanip>

using namespace std;

int n, r;
int chosen[25]; // chosen[step] 用于记录当前组合中第 step 个位置选定的数字

/**
 * 递归枚举所有组合
 * @param step  当前正在确定组合中的第几个位置（从 1 到 r）
 * @param start 当前位置允许选择的最小起始数字（保证组合内元素严格递增）
 */
void dfs(int step, int start) {
    // 递归边界：当 step > r 时，说明前 r 个位置已全部选定，按场宽格式输出
    if (step > r) {
        for (int i = 1; i <= r; ++i) {
            cout << setw(3) << chosen[i];
        }
        cout << "\n";
        return;
    }

    // 枚举当前第 step 个位置填入的数字 i
    // 可行性剪枝：剩余可选数字个数 (n - i) 必须不少于后续还需填满的位置数 (r - step)
    // 因此 i 的最大合法取值为 n - (r - step)
    for (int i = start; i <= n - (r - step); ++i) {
        chosen[step] = i;       // 在第 step 个位置放入数字 i
        dfs(step + 1, i + 1);   // 递归确定第 step + 1 个位置，下界从 i + 1 开始
    }
}

int main() {
    // 读取元素总数 n 和抽取个数 r
    cin >> n >> r;

    // 从第 1 个位置开始搜索，初始可选最小数字为 1
    dfs(1, 1);

    return 0;
}
