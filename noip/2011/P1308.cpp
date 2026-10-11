/**
 * Problem: luogu-P1308 [NOIP2011 普及组] 统计单词数
 * Algorithm: 字符串检索 · 双端空格哨兵法 (Space Sentinel Padding)
 * Standard: C++11 (CCF GESP / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word, article;

    // 读入目标单词与整篇待检索文章
    getline(cin, word);
    getline(cin, article);

    // 步骤一：全量转为小写字母，实现大小写不敏感匹配
    for (char &c : word) {
        c = tolower(c);
    }
    for (char &c : article) {
        c = tolower(c);
    }

    // 步骤二：核心哨兵法——两端各补一个空格
    // 强制将"独立单词"界定转化为"两端均为空格的子串检索"，天然消除行首行尾边界特判
    string search_word = " " + word + " ";
    string search_art = " " + article + " ";

    int cnt = 0;           // 记录匹配出现的总次数
    int first_pos = -1;    // 记录在原文章中第一次出现的起始下标
    size_t pos = search_art.find(search_word);

    // 步骤三：循环检索所有匹配出现的独立单词
    while (pos != string::npos) {
        if (cnt == 0) {
            // search_art 中左侧空格的索引 pos，恰好精确等于原文章中的首字母索引
            first_pos = pos;
        }
        cnt++;
        // 推进到下一个位置继续检索
        pos = search_art.find(search_word, pos + 1);
    }

    // 步骤四：输出结果
    if (cnt == 0) {
        cout << -1 << "\n";
    } else {
        cout << cnt << " " << first_pos << "\n";
    }

    return 0;
}
