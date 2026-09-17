/**
 * 题目: 【GESP】C++四级真题 luogu-B3851 [GESP202306 四级] 图像压缩
 * 题号: B3851
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 4 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3851/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

// 将16进制字符串转为整数
// 将16进制字符串转换为整数
// 参数str: 16进制字符串
// 返回: 转换后的整数
// 使用std::stoi进行转换,第二个参数nullptr表示不需要返回转换结束位置
// 第三个参数16表示按16进制转换
int hexstr_to_int(const std::string& str) {
    return std::stoi(str, nullptr, 16);
}

/*
本函数实现了一个整数到固定位数16进制字符串的转换。主要思路和原理如下：

1. 字符映射表
   - 使用静态数组hex_digits存储16进制的所有可能字符(0-F)
   - 数组索引0-15正好对应16进制的0-F
   - 使用static确保字符表只初始化一次

2. 结果字符串初始化
   - 使用std::string的构造函数创建指定长度的字符串
   - 初始全部填充'0'字符,保证位数不足时高位补0
   - bit参数控制输出的16进制位数

3. 进制转换过程
   - 从右向左(低位到高位)处理每一位
   - 使用num % 16获取当前位的值(0-15)
   - 将余数作为hex_digits的索引获取对应字符
   - num /= 16实现右移4位,处理下一个16进制位
*/
std::string int_to_hexstr(int num, int bit) {
    // 定义16进制字符表,0-F对应的字符
    static const char hex_digits[] = "0123456789ABCDEF";
    // 创建指定长度的字符串,初始全为'0'
    std::string res(bit, '0');
    // 从低位到高位,依次取num的每位转成16进制字符
    for (int i = bit - 1; i >= 0; --i) {
        res[i] = hex_digits[num % 16]; // 取余得到当前位对应的16进制数
        num /= 16;
    }
    return res;
}

// 颜色频率比较函数
// 参数:
// - a,b: 待比较的两个颜色频率对(颜色值,出现次数)
// 返回: 比较结果
// 规则: 频率高的优先;频率相同时颜色值小的优先
bool compare_pair(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

// 将颜色值映射到最接近的标准颜色索引
// 参数:
// - color_num: 原始颜色值
// - top_color: 标准颜色表
// 返回: 最接近的标准颜色的索引(0-15)
int trans_color(int color_num, const std::vector<int>& top_color) {
    int min_diff = 1000000000; // 初始化最小差值
    int min_index = 0; // 记录最小差值对应的颜色索引
    // 遍历所有标准颜色
    for (int i = 0; i < 16; ++i) {
        // 计算当前颜色与标准颜色的差值
        int diff = std::abs(color_num - top_color[i]);
        // 如果找到更小的差值,更新记录
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    std::cin >> n; // 读入图像行数

    // 创建二维vector存储图像数据
    std::vector<std::vector<int>> colors_vec(n);
    // 创建vector存储每种颜色的频率统计
    // pair的first存颜色值,second存频率
    std::vector<std::pair<int, int>> color_freq(256, {0, 0});

    // 读入图像数据并统计颜色频率
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        // 每两个字符表示一个颜色值
        for (size_t j = 0; j < str.length(); j += 2) {
            // 转换16进制字符串为整数
            int color_num = hexstr_to_int(str.substr(j, 2));
            // 保存颜色值
            colors_vec[i].push_back(color_num);
            // 更新颜色频率统计
            color_freq[color_num].second++;
            color_freq[color_num].first = color_num;
        }
    }

    // 按频率排序所有颜色
    std::sort(color_freq.begin(), color_freq.end(), compare_pair);

    // 选取前16种最常见的颜色
    std::vector<int> top_color;
    for (int i = 0; i < 16 && i < (int)color_freq.size(); ++i) {
        top_color.push_back(color_freq[i].first);
    }

    // 输出16种标准颜色的16进制表示
    for (int i = 0; i < 16; i++) {
        std::cout << int_to_hexstr(top_color[i], 2);
    }
    std::cout << "\n";

    // 输出压缩后的图像
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < colors_vec[i].size(); j++) {
            // 将每个颜色映射到最接近的标准颜色
            int trans_color_num = trans_color(colors_vec[i][j], top_color);
            // 输出映射后的颜色索引(1位16进制)
            std::cout << int_to_hexstr(trans_color_num, 1);
        }
        std::cout << "\n";
    }
}
