/**
 * 题目: 【GESP/CSP练习】GESP八级 / CSP-S 题解：luogu-P3375 【模板】KMP
 * 题号: P3375
 * 归属: GESP八级 / CSP-S / 字符串算法·KMP单模式匹配与next数组
 * 博客: https://www.coderli.com/gesp-8-luogu-p3375/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 最大字符串长度常量定义
const int MAXN = 1000005;

// nxt[i] 存储模式串 s2 前缀子串 s2[0...i] 的最长相等真前后缀长度 (即最长 border 长度)
int nxt[MAXN];

/**
 * 预处理模式串 s2 的最长 border 数组（即 KMP 的 next / 前缀函数数组）
 * 利用已匹配的前缀自相似性，递推计算每个前缀子串的最长 border 长度
 * 
 * @param s 待预处理的模式串 (采用 0-indexed 标准)
 * @param m 模式串长度
 */
void build_next(const string& s, int m) {
    // 长度为 1 的前缀不存在非自身的真前后缀，border 长度定义为 0
    nxt[0] = 0;
    
    // j 维护当前所能匹配的最长 border 候选长度
    int j = 0;
    for (int i = 1; i < m; ++i) {
        // 当下一个字符不匹配且 j > 0 时，沿 border 链回退到次长 border 继续尝试扩展
        while (j > 0 && s[i] != s[j]) {
            j = nxt[j - 1];
        }
        // 如果当前字符匹配成功，最长 border 长度增加 1
        if (s[i] == s[j]) {
            ++j;
        }
        // 记录长度为 i + 1 的前缀的最长 border 长度
        nxt[i] = j;
    }
}

/**
 * KMP 模式匹配主算法
 * 在主串 s1 中高效检索模式串 s2 的所有出现位置
 * 利用 border 性质避免主串指针回溯，使匹配过程保持线性推进
 * 
 * @param s1 文本主串
 * @param s2 目标模式串
 */
void kmp_search(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    
    // 模式串当前匹配到的字符数 (对应前缀 s2[0...j-1])
    int j = 0;
    for (int i = 0; i < n; ++i) {
        // 字符失配时，主串指针 i 不回退，模式串指针 j 沿 next 数组向左回退
        while (j > 0 && s1[i] != s2[j]) {
            j = nxt[j - 1];
        }
        // 当前字符匹配成功，匹配长度递增
        if (s1[i] == s2[j]) {
            ++j;
        }
        // 完整匹配到了模式串 s2
        if (j == m) {
            // 按照题目要求输出 1-based 起始下标: (i - m + 1) + 1 = i - m + 2
            cout << (i - m + 2) << "\n";
            // 模式串完整匹配后，视作在最后一个位置发生失配，回退至次长 border 寻找重叠出现
            j = nxt[j - 1];
        }
    }
}

int main() {
    // 主串 s1 与模式串 s2
    string s1, s2;
    cin >> s1 >> s2;

    int m = s2.size();

    // 1. 预处理模式串 s2 的前缀函数 (border 数组)
    build_next(s2, m);

    // 2. 在主串 s1 中匹配模式串 s2 并输出所有出现位置
    kmp_search(s1, s2);

    // 3. 按照格式输出 s2 每个前缀的最长 border 长度
    for (int i = 0; i < m; ++i) {
        cout << nxt[i] << (i + 1 == m ? "\n" : " ");
    }

    return 0;
}
