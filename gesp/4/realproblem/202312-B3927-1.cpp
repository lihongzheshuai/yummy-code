/**
 * 题目: 【GESP】C++四级真题 luogu-B3927 [GESP202312 四级] 小杨的字典
 * 题号: B3927
 * 归属: GESP4级 (202312认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3927/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

// 存储A语言单词的数组
std::string a_str_array[105];
// 存储B语言单词的数组，与a_str_array下标一一对应
std::string b_str_array[105];

/**
 * 判断字符是否为小写字母
 * @param c 待判断的字符
 * @return 如果是小写字母返回true，否则返回false
 */
bool is_lower(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

/**
 * 根据A语言单词查找对应的B语言翻译
 * @param input A语言单词
 * @return 如果找到返回对应的B语言翻译，否则返回"UNK"
 */
std::string get_b_str(std::string input) {
    for (int i = 0; i < 105; i++) {
        if (input == a_str_array[i]) {
            return b_str_array[i];
        }
    }
    return "UNK";
}

int main() {
    // 读入字典条目数
    int n;
    std::cin >> n;

    // 读入字典内容
    for (int i = 0; i < n; i++) {
        std::cin >> a_str_array[i];
        std::cin >> b_str_array[i];
    }

    // 读入待翻译的文章
    std::string input_str;
    std::cin >> input_str;

    // 存储翻译结果
    std::string output_str = "";
    // 临时存储当前正在处理的单词
    std::string word = "";

    // 遍历输入文章的每个字符
    for (int i = 0; i < input_str.length(); i++) {
        // 当前字符是小写字母时的处理
        if (is_lower(input_str[i])) {
            // 如果是小写字母，将其追加到当前正在构建的单词中
            // 例如：处理"abc"时，依次将'a','b','c'加入word中
            word += input_str[i];
        } else {
            // 当前字符是标点符号时的处理
            // 如果已经积累了一个单词(word不为空)，需要先处理这个单词
            if (word.length() > 0) {
                // 查找这个A语言单词对应的B语言翻译
                // 例如：word为"abc"时，查找得到对应的翻译"a"
                std::string b_str = get_b_str(word);
                // 将翻译后的单词加入到最终结果字符串中
                output_str += b_str;
                // 清空word，准备处理下一个单词
                word = "";
            }
            // 将当前的标点符号直接加入到结果字符串中
            // 标点符号在A语言和B语言中保持不变
            output_str += input_str[i];
        }
    }

    // 处理最后一个单词（如果存在）
    if (word.length() > 0) {
        std::string b_str = get_b_str(word);
        output_str += b_str;
    }

    // 输出翻译结果
    std::cout << output_str;
    return 0;
}
