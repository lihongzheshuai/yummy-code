/**
 * 题目: 【GESP】C++三级真题 luogu-B3926 [GESP202312 三级] 单位转换
 * 题号: B3926
 * 归属: GESP3级 (202312认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3926/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取题目数量
    int n;
    std::cin >> n;
    // 清除输入缓冲区中的换行符，避免影响后续的getline读取
    std::cin.ignore();

    // 循环处理每个转换题目
    for (int i = 0; i < n; i++) {
        std::string str;
        // 读取一整行输入
        getline(std::cin, str);

        // 查找关键位置索引
        std::size_t first_blank_idx = str.find(" ");  // 第一个空格位置
        std::size_t second_blank_idx = str.find(" ", first_blank_idx + 1);  // 第二个空格位置
        std::size_t question_idx = str.find("?");  // 问号位置

        // 提取单位信息
        std::string big_unit = str.substr(
            first_blank_idx + 1, second_blank_idx - first_blank_idx - 1);  // 大单位
        std::string small_unit =
            str.substr(question_idx + 2, str.length() - question_idx - 2);  // 小单位

        // 提取数值并转换为整数
        int first_num = std::stoi(str.substr(0, first_blank_idx));
        int second_num;

        // 根据单位类型进行转换计算
        if (big_unit == "km" || big_unit == "kg") {
            if (small_unit == "m" || small_unit == "g") {
                second_num = first_num * 1000;  // 千米转米或千克转克
            } else if (small_unit == "mm" || small_unit == "mg") {
                second_num = first_num * 1000 * 1000;  // 千米转毫米或千克转毫克
            }
        } else if (big_unit == "m" || big_unit == "g") {
            second_num = first_num * 1000;  // 米转毫米或克转毫克
        }

        // 按格式输出结果
        std::cout << first_num << " " << big_unit << " " << "=" << " "
                  << second_num << " " << small_unit << std::endl;
    }
    return 0;
}
