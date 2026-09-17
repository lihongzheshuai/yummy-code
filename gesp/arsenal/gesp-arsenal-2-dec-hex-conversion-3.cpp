/**
 * 题目: 【GESP/CSP】编程武器库-2, 十进制转换十六进制
 * 题号: 
 * 归属: CSP-J
 * 解法: 解法 3 / 共 7 种解法
 * 博客: https://www.coderli.com/gesp-arsenal-2-dec-hex-conversion/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

int main() {
    int n = 255;

    printf("%x\n", n);    // ff （小写）
    printf("%X\n", n);    // FF （大写）
    printf("%04x\n", n);  // 00ff （补位）
    printf("%#X\n", n);   // 0XFF （带前缀）
    printf("%#06x\n", n); // 0x00FF （带前缀并补位）
    return 0;
}
