/**
 * 题目: 【GESP】C++一级知识点研究，scanf/printf浮点数格式化到底是%lf还是%f
 * 题号: 
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-knowledge-scanf-printf-floatnumber/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

int main() {
    double num = 3.14159;
    printf("%f\n", num);  // 正确，输出 3.141590
    return 0;
}
