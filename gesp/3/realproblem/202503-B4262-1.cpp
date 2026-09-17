/**
 * 题目: 【GESP】C++三级真题 luogu-B4262 [GESP202503 三级] 词频统计
 * 题号: B4262
 * 归属: GESP3级 (202503认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4262/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    // 读取单词数量
    int n;
    std::cin >> n;
    // 记录最大出现次数
    int max_count = 0;
    // 存储不重复的单词数组
    std::string str_ary[n];
    // 存储每个单词出现的次数
    int count_ary[n] = {0};
    // 当前不重复单词的索引
    int cur_idx = 0;

    // 循环读取n个单词
    while (n--) {
        std::string str;
        std::cin >> str;
        // 将单词转换为小写
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        // 标记当前单词是否已存在
        bool is_exist = false;

        // 在已有单词中查找是否存在
        for (int i = 0; i < cur_idx; i++) {
            if (str == str_ary[i]) {
                is_exist = true;
                // 已存在则计数加1
                count_ary[i]++;
                // 更新最大出现次数
                max_count = std::max(max_count, count_ary[i]);
                break;
            }
        }

        // 如果是新单词，则添加到数组中
        if (!is_exist) {
            str_ary[cur_idx] = str;
            count_ary[cur_idx]++;
            cur_idx++;
            // 更新最大出现次数
            max_count = std::max(max_count, count_ary[cur_idx - 1]);
        }
    }

    // 查找并输出出现次数最多的单词
    for (int i = 0; i < cur_idx; i++) {
        if (count_ary[i] == max_count) {
            std::cout << str_ary[i];
            break;
        }
    }
    return 0;
}
