/**
 * 题目: 【GESP】C++三级真题 luogu-B4262 [GESP202503 三级] 词频统计
 * 题号: B4262
 * 归属: GESP3级 (202503认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4262/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

int main() {
    // 读取单词数量
    int n;
    std::cin >> n;
    // 使用map存储单词及其出现次数
    std::map<std::string, int> count_m;
    // 记录最大出现次数
    int max_count = 0;
    // 循环读取n个单词
    while (n--) {
        std::string str;
        std::cin >> str;
        // 将单词转换为小写
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        // 更新单词出现次数并更新最大出现次数
        count_m[str]++;
        max_count = std::max(max_count, count_m[str]);
    }
    // 遍历map查找出现次数最多的单词并输出
    for (const auto& map: count_m) {
        if (map.second == max_count) {
            std::cout << map.first;
            break;
        }
    }
    return 0;
}
