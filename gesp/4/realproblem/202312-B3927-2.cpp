/**
 * 题目: 【GESP】C++四级真题 luogu-B3927 [GESP202312 四级] 小杨的字典
 * 题号: B3927
 * 归属: GESP4级 (202312认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3927/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <map>
#include <string>
#include <iostream>
#include <cctype>

int main() {
    // 读入字典条目数
    int n;
    std::cin >> n;

    // 创建字典，使用map存储A语言到B语言的映射关系
    std::map<std::string, std::string> dict;

    // 读入n组A语言和B语言的对应关系
    for (int i = 0; i < n; i++) {
        std::string A, B;
        std::cin >> A >> B;
        dict[A] = B;  // 将A语言单词作为键，B语言单词作为值存入字典
    }

    // 读入需要翻译的A语言文章
    std::string input_str;
    std::cin >> input_str;

    // 存储翻译结果
    std::string result = "";

    // 遍历输入文章的每个字符
    int i = 0;
    while (i < input_str.length()) {
        // 如果当前字符是小写字母，说明遇到了一个单词
        if (islower(input_str[i])) {
            std::string word = "";  // 用于存储当前正在处理的单词

            // 持续读取小写字母，直到遇到非小写字母或到达字符串末尾
            while (i < input_str.length() && islower(input_str[i])) {
                word += input_str[i];  // 将字母加入当前单词
                i++;
            }

            // 检查单词是否在字典中
            if (dict.count(word)) {
                result += dict[word];  // 如果在字典中，添加对应的B语言翻译
            } else {
                result += "UNK";       // 如果不在字典中，添加"UNK"
            }
        } else {
            // 如果是标点符号，直接添加到结果中
            result += input_str[i];
            i++;
        }
    }

    // 输出翻译结果
    std::cout << result << std::endl;
    return 0;
}
