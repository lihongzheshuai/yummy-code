/**
 * 题目: 【GESP】C++二级练习 luogu-B3844, [GESP样题 二级] 画正方形
 * 题号: B3844
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3844/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 读取输入的最大值
    cin >> n;
    int start_char = 'A'; // 初始化起始字符为'A'
    int end_char = 'A' + 25; // 计算结束字符为'A' + 25
    for (int i = 1; i <= n; i++) { // 外层循环控制行数
        for (int j = 0; j < n; j++) { // 内层循环控制列数
            int current_ascii = start_char + j % 26; // 计算当前字符的ASCII码
            if (current_ascii > end_char) { // 如果当前字符的ASCII码超过结束字符的ASCII码
                current_ascii -= 26; // 调整当前字符的ASCII码
            }
            cout << (char)current_ascii; // 输出当前字符
        }
        cout << endl; // 换行
        start_char++; // 每行后，起始字符向后移动一个
        if (start_char > end_char) { // 如果起始字符超过结束字符
            start_char -= 26; // 调整起始字符
        }
    }
    return 0;
}
