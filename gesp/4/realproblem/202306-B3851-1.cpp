/**
 * 题目: 【GESP】C++四级真题 luogu-B3851 [GESP202306 四级] 图像压缩
 * 题号: B3851
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 1 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3851/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

// 定义颜色信息结构体,包含颜色值和出现频率
struct color_info {
    int color_num;  // 颜色值
    int freq;       // 出现频率
};

// 定义全局颜色数组,用于统计256种颜色的频率
struct color_info colors[256];

// 将16进制字符串转换为整数
int hexstr_to_int(std::string str) {
    return std::stoi(str, nullptr, 16);
}

// 将整数转换为指定位数的16进制字符串
std::string int_to_hexstr(int num, int bit) {
    // 创建字符串流对象
    std::stringstream ss;
    // 设置输出格式:
    // setw(bit) - 设置输出宽度为bit位
    // setfill('0') - 不足位数用0填充
    // hex - 以16进制格式输出
    // uppercase - 字母以大写形式输出
    // num - 要转换的数字
    ss << std::setw(bit) << std::setfill('0') << std::hex << std::uppercase << num;
    return ss.str();
}

// 颜色信息比较函数,用于排序
// 频率相同时按颜色值升序,否则按频率降序
bool compare(color_info a, color_info b) {
    return a.freq == b.freq ? a.color_num < b.color_num : a.freq > b.freq;
}

// 将原始颜色转换为最接近的16种颜色之一
int trans_color(int color_num, struct color_info top_color[16]) {
    int min_diff = 1000000000;  // 初始化最小差值
    int min_index = 0;          // 记录最接近颜色的索引
    // 遍历16种标准颜色
    for (int i = 0; i < 16; i++) {
        // 计算当前颜色与标准颜色的差值的绝对值
        int diff = abs(color_num - top_color[i].color_num);
        // 如果找到更小的差值
        if (diff < min_diff) {
            // 更新最小差值
            min_diff = diff;
            // 记录对应的颜色索引
            min_index = i;
        }
        // 如果差值相等，由于i是从小到大遍历的
        // 自动保证了相等时取较小索引的规则
    }
    return min_index;
}

int main() {
    int n;
    std::cin >> n;
    // 存储图像的二维向量
    std::vector<std::vector<int>> colors_vec(n);

    // 读取输入并统计颜色频率
    // 外层循环处理n行输入
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        // 内层循环每次处理2个字符(1个颜色值)
        for (int j = 0; j < str.length(); j+=2) {
            // 将2个16进制字符转换为整数颜色值
            int color_num = hexstr_to_int(str.substr(j, 2));
            // 将颜色值存入二维向量对应行
            colors_vec[i].push_back(color_num);
            // 更新颜色频率统计
            colors[color_num].freq++;
            // 设置颜色值(用于后续排序)
            colors[color_num].color_num = color_num;
        }
    }

    // 按频率排序所有颜色
    std::sort(colors, colors + 256,compare);

    // 选取前16种最常见的颜色
    struct color_info top_color[16];

    // 输出16种颜色的16进制值
    for (int i = 0; i < 16; i++) {
        top_color[i] = colors[i];
        std::cout << int_to_hexstr(top_color[i].color_num,2);
    }
    std::cout << "\n";

    // 转换并输出压缩后的图像
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < colors_vec[i].size(); j++) {
            int trans_color_num = trans_color(colors_vec[i][j], top_color);
            std::cout << int_to_hexstr(trans_color_num, 1);
        }
        std::cout << "\n";
    }

}
