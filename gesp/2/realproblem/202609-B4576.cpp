/**
 * 题目: 【GESP真题】GESP二级题解：luogu-B4576 [GESP202609 二级] 字符变换
 * 题号: B4576
 * 归属: GESP2级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4576-char-transform/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4576
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 初始化 8 行 16 列画布，默认填充 '*'
    char grid[8][16];
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 16; ++c) {
            grid[r][c] = '*';
        }
    }

    // 读取三个正整数编号并进行字符替换
    int code;
    for (int i = 0; i < 3; ++i) {
        if (cin >> code) {
            int idx = code - 1; // 转换为 0-indexed
            int r = idx / 16;   // 计算对应行
            int c = idx % 16;   // 计算对应列
            if (r >= 0 && r < 8 && c >= 0 && c < 16) {
                grid[r][c] = (char)code; // ASCII 强转为字符
            }
        }
    }

    // 格式化输出画布
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 16; ++c) {
            cout << grid[r][c];
        }
        cout << "\n";
    }

    return 0;
}
