/**
 * 题目: 【GESP】C++二级真题 luogu-B3837, [GESP202303 二级] 画三角形
 * 题号: B3837
 * 归属: GESP2级 (202303认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3837/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 读取输入的正整数n
    cin >> n; // 从输入流中读取n的值
    int start_char = 'A'; // 初始化起始字符为'A'
    int idx = 0; // 初始化索引为0
    for (int i = 1; i <= n; i++) { // 外层循环控制行数
        for (int j = 1; j <= i; j++) { // 内层循环控制列数
            int current_ascii = start_char + idx % 26; // 计算当前字符的ASCII码
            cout << (char)current_ascii; // 输出当前字符
            idx++; // 索引自增
        }
        cout << endl; // 换行以开始下一行的输出
    }
    return 0;
}
