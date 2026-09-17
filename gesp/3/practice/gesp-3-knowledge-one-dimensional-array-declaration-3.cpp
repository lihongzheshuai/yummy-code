/**
 * 题目: 【GESP】C++三级知识点研究，一维数组声明合法性
 * 题号: 
 * 归属: GESP3级
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-knowledge-one-dimensional-array-declaration/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <vector>

std::vector<int> arr = {1, 2, 3};
arr.push_back(4); // 添加元素

std::cout << arr[3]; // 输出4
