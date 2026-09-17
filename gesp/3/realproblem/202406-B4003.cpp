/**
 * 题目: 【GESP】C++三级真题 luogu-B4003 [GESP202406 三级] 移位
 * 题号: B4003
 * 归属: GESP3级 (202406认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4003/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取偏移量
    int n;
    std::cin >> n;

    // 遍历26个大写字母
    for (int i = 0; i < 26; i++) {
        // 计算偏移后的ASCII码值
        int cur_idx = 'A' + i + n % 26;
        // 如果超出'Z'的ASCII码值，需要回环到字母表开头
        if (cur_idx > 'Z') {
            cur_idx -= 26;
        }
        // 输出偏移后的字符
        std::cout << char(cur_idx);
    }
    return 0;
}
