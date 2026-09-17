/**
 * 题目: 【GESP】C++三级知识点研究，一维数组声明合法性
 * 题号: 
 * 归属: GESP3级
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-knowledge-one-dimensional-array-declaration/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <array>

std::array<int, 3> arr = {1, 2, 3};

arr[1] = 42; // 访问第二个元素
