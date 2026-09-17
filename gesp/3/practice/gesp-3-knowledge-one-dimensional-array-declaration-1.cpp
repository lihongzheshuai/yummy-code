/**
 * 题目: 【GESP】C++三级知识点研究，一维数组声明合法性
 * 题号: 
 * 归属: GESP3级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-knowledge-one-dimensional-array-declaration/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

int size = 5;
int* arr = new int[size]; // 分配长度为5的数组

arr[0] = 42; // 访问元素

delete[] arr; // 释放内存
