#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

/*
    题目思路详解：
    1. 首先统计所有输入颜色的出现频率，并记录每种颜色的编号。
    2. 然后将所有颜色按出现频率从高到低排序，若频率相同则按颜色编号从小到大排序。
    3. 选出出现频率最高的16种颜色，作为“主色板”。
    4. 对于每一行的颜色，将其映射到主色板中最接近的颜色（按编号距离最近），输出其在主色板中的索引（1位16进制）。
    5. 最后输出主色板的16种颜色编号，以及每行颜色映射后的索引序列。
*/

// 颜色信息结构体，包含颜色编号和出现频率
struct color_info {
    int color_num; // 颜色编号
    int freq;      // 颜色出现频率
};

// 全部256种颜色的信息数组，初始频率为0
struct color_info colors[256];

// 将16进制字符串转为整数
int hexstr_to_int(std::string str) {
    // 使用std::stoi将16进制字符串转为整数
    return std::stoi(str, nullptr, 16);
}

// 将整数转为指定位数的16进制字符串（高位补0）
std::string int_to_hexstr(int num, int bit) {
    // 预定义16进制字符
    static const char hex_digits[] = "0123456789ABCDEF";
    std::string res(bit, '0');
    // 从低位到高位依次填充
    for (int i = bit - 1; i >= 0; --i) {
        res[i] = hex_digits[num % 16];
        num /= 16;
    }
    return res;
}

// 比较函数：先按频率降序，频率相同按颜色编号升序
bool compare(color_info a, color_info b) {
    // 如果频率相同，按颜色编号升序；否则按频率降序
    return a.freq == b.freq ? a.color_num < b.color_num : a.freq > b.freq;
}

// 将颜色编号映射到最接近的top_color数组中的颜色索引
int trans_color(int color_num, struct color_info top_color[16]) {
    int min_diff = 1000000000; // 初始化最小差值为极大值
    int min_index = 0;         // 最小差值对应的索引
    // 遍历主色板，找到与当前颜色编号差值最小的主色
    for (int i = 0; i < 16; i++) {
        int diff = abs(color_num - top_color[i].color_num);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    // 1. 读取输入的行数
    int n;
    std::cin >> n;

    // 2. colors_vec用于存储每行的颜色编号序列
    std::vector<std::vector<int>> colors_vec(n);

    // 3. 统计每种颜色的出现频率，并记录每行的颜色编号
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str; // 输入一行颜色字符串
        for (int j = 0; j < str.length(); j += 2) {
            // 每两个字符为一个颜色，转为整数编号
            int color_num = hexstr_to_int(str.substr(j, 2));
            colors_vec[i].push_back(color_num); // 存储到当前行
            colors[color_num].freq++;           // 统计频率
            colors[color_num].color_num = color_num; // 记录颜色编号
        }
    }

    // 4. 对所有颜色按频率排序，选出出现频率最高的16种颜色
    std::sort(colors, colors + 256, compare);

    struct color_info top_color[16]; // 存储前16种颜色

    // 5. 输出主色板的16种颜色编号（2位16进制，不足补0）
    for (int i = 0; i < 16; i++) {
        top_color[i] = colors[i];
        std::cout << int_to_hexstr(top_color[i].color_num, 2);
    }
    std::cout << "\n";

    // 6. 对每一行的颜色进行映射，并输出映射后的索引（1位16进制）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < colors_vec[i].size(); j++) {
            // 将当前颜色编号映射到主色板中最接近的颜色索引
            int trans_color_num = trans_color(colors_vec[i][j], top_color);
            // 输出该索引的1位16进制表示
            std::cout << int_to_hexstr(trans_color_num, 1);
        }
        std::cout << "\n";
    }

    // 程序结束
}