/**
 * 题目: 【GESP】C++一级知识点研究，布尔(bool)型变量
 * 题号: 
 * 归属: GESP1级
 * 解法: 解法 2 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-knowledge-bool/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

bool x = true;
bool y = false;

bool result1 = x && y;  // result1 为 false，因为 x 和 y 必须都为 true
bool result2 = x || y;  // result2 为 true，因为 x 或 y 至少有一个为 true
bool result3 = !x;      // result3 为 false，x 为 true，因此取反后为 false
