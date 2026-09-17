#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

/*
    题目思路详解：
    1. 首先统计所有输入颜色的出现频率，并记录每种颜色的编号。
    2. 然后将所有颜色按出现频率从高到低排序，若频率相同则按颜色编号从小到大排序。
    3. 选出出现频率最高的16种颜色，作为“主色板”。
    4. 对于每一行的颜色，将其映射到主色板中最接近的颜色（按编号距离最近），输出其在主色板中的索引（1位16进制）。
    5. 最后输出主色板的16种颜色编号，以及每行颜色映射后的索引序列。
*/

// 将16进制字符串转为整数
int hexstr_to_int(const std::string& str) {
    return std::stoi(str, nullptr, 16);
}

// 将整数转为指定位数的16进制字符串（高位补0）
std::string int_to_hexstr(int num, int bit) {
    static const char hex_digits[] = "0123456789ABCDEF";
    std::string res(bit, '0');
    for (int i = bit - 1; i >= 0; --i) {
        res[i] = hex_digits[num % 16];
        num /= 16;
    }
    return res;
}

// 比较函数：先按频率降序，频率相同按颜色编号升序
bool compare_pair(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

// 将颜色编号映射到最接近的top_color数组中的颜色索引
int trans_color(int color_num, const std::vector<int>& top_color) {
    int min_diff = 1000000000;
    int min_index = 0;
    for (int i = 0; i < 16; ++i) {
        int diff = std::abs(color_num - top_color[i]);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> colors_vec(n);
    std::vector<std::pair<int, int>> color_freq(256, {0, 0});

    // // 初始化颜色编号
    // for (int i = 0; i < 256; ++i) {
    //     color_vec[i].first = i;
    //     color_vec[i].second = 0;
    // }

    // 统计每种颜色的出现频率，并记录每行的颜色编号
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        for (size_t j = 0; j < str.length(); j += 2) {
            int color_num = hexstr_to_int(str.substr(j, 2));
            colors_vec[i].push_back(color_num);
            color_freq[color_num].second++;
            color_freq[color_num].first = color_num;
        }
    }
    std::sort(color_freq.begin(), color_freq.end(), compare_pair);

    // 选出出现频率最高的16种颜色
    std::vector<int> top_color;
    for (int i = 0; i < 16 && i < (int)color_freq.size(); ++i) {
        top_color.push_back(color_freq[i].first);
    }


    // 输出主色板的16种颜色编号（2位16进制，不足补0）
    for (int i = 0; i < 16; i++) {
        std::cout << int_to_hexstr(top_color[i], 2);
    }
    std::cout << "\n";

    // 对每一行的颜色进行映射，并输出映射后的索引（1位16进制）
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < colors_vec[i].size(); j++) {
            int trans_color_num = trans_color(colors_vec[i][j], top_color);
            std::cout << int_to_hexstr(trans_color_num, 1);
        }
        std::cout << "\n";
    }
}