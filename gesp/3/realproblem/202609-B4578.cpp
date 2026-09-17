/**
 * 题目: 【GESP真题】GESP三级 / CSP-J 题解：luogu-B4578 [GESP202609 三级] 分割字符串
 * 题号: B4578
 * 归属: GESP3级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4578-split-string/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4578
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!getline(cin, s)) {
        return 0;
    }

    int k = 1;
    while (true) {
        // 构造连续 k 个空格的匹配目标
        string pattern(k, ' ');
        size_t pos = s.find(pattern);
        if (pos == string::npos) {
            break;
        }

        // 输出左侧截取的子串
        string left_part = s.substr(0, pos);
        cout << left_part << "\n";

        // 更新右侧剩余字符串并递增所需空格数
        s = s.substr(pos + k);
        k++;
    }

    // 输出最终右侧剩余部分
    cout << s << "\n";

    return 0;
}
