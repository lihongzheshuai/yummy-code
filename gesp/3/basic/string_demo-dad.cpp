#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include<bits/stdc++.h>

using namespace std;
// （6）掌握字符串及其函数的使用包括但不限于大小写转换、字符串搜索、分割、替换。
int main() {
    // 字符串定义代码
    string str1 = "runoob";
    string str2 = "Google";

    cout << str1 << " Size: " << str1.size() << endl;
    cout << str2 << " Size: " << str2.size() << endl;

    // 字符串大小写转换
    string str3 = str1;
    string str4 = str2;
    transform(str1.begin(), str1.end(), str3.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str4.begin(), ::tolower);

    cout << str3 << endl;
    cout << str4 << endl;

    // 字符串搜索
    // 从头寻找
    size_t pos = str1.find("noo");
    if (pos != string::npos) {
        cout << "Found 'noo' at position: " << pos << endl;
    }

    // 从尾寻找，最后一次出现
    string str = "C++ is fun, C++ is powerful!";
    size_t pos_r = str.rfind("C++");
    if (pos_r != string::npos) {
        cout << "Last found 'C++' at position: " << pos_r << endl;
    }

    //功能: 查找字符串中第一个匹配给定字符集中的字符的位置。
    //返回值: 返回第一个匹配字符的位置，或 npos。
    //使用场景: 用于查找一组字符中的任意一个，例如查找分隔符。
    string str_5 = "email: user@example.com";
    size_t pos_f = str_5.find_first_of("@.:"); // 查找 '@'、'.' 或 ':' 中的任意一个
    if (pos_f != string::npos) {
        cout << "找到第一个匹配字符在位置: " << pos_f << endl;
    }

    //功能: 查找字符串中最后一个匹配给定字符集中的字符的位置。
    //返回值: 返回最后一个匹配字符的位置，或 npos。
    //使用场景: 用于查找一组字符中的任意一个，例如查找分隔符。
    string str_6 = "email: user@example.com";
    size_t pos_l = str_6.find_last_of("@.:"); // 查找 '@'、'.' 或 ':' 中的任意一个
    if (pos_l != string::npos) {
        cout << "找到最后一个匹配字符在位置: " << pos_l << endl;
    }

    //功能: 查找字符串中第一个匹配给定子字符串的位置。
    //返回值: 返回第一个匹配子字符串的位置，或 npos。
    //使用场景: 用于查找子字符串。
    string str_7 = "  C++ is fun, C++ is powerful!";
    size_t pos_s = str_7.find("C++"); // 查找子字符串 "C++"
    if (pos_s != string::npos) {
        cout << "找到子字符串 'C++' 在位置: " << pos_s << endl;
    }

    //功能: 查找字符串中最后一个匹配给定子字符串的位置。
    //返回值: 返回最后一个匹配子字符串的位置，或 npos。
    //使用场景: 用于查找子字符串。
    string str_8 = "  C++ is fun, C++ is powerful!";
    size_t pos_s_r = str_8.rfind("C++"); // 查找子字符串 "C++"
    if (pos_s_r != string::npos) {
        cout << "找到子字符串 'C++' 在位置: " << pos_s_r << endl;
    }

    //功能: 查找字符串中第一个不匹配给定字符集中的字符的位置。
    //返回值: 返回第一个不匹配字符的位置，或 npos。
    //使用场景: 用于查找一组字符中的任意一个，例如查找分隔符。
    string str_9 = ":email: user@example.com";
    size_t pos_nf = str_9.find_first_not_of("@.: "); // 查找 '@'、'.'、':'、' ' 或空字符之外的任意一个
    if (pos_nf != string::npos) {
        cout << "找到第一个不匹配字符在位置: " << pos_nf << endl;
    }

    //功能: 查找字符串中最后一个不匹配给定字符集中的字符的位置。
    //返回值: 返回最后一个不匹配字符的位置，或 npos。
    //使用场景: 用于查找一组字符中的任意一个，例如查找分隔符。
    string str_10 = ":email: user@example.com";
    size_t pos_nf_r = str_10.find_last_not_of("@.: "); // 查找 '@'、'.'、':'、' ' 或空字符之外的任意一个
    if (pos_nf_r != string::npos) {
        cout << "找到最后一个不匹配字符在位置: " << pos_nf_r << endl;
    }

    const char* str_c = "C++ programming is fun!";
    const char* target = "programming";
    
    const char* result = strstr(str_c, target);
    if (result != nullptr) {
        cout << result << endl;
        cout << "找到 '" << target << "' 在位置: " << (result - str_c   ) << endl;
    } else {
        cout << "未找到 '" << target << "'" << endl;
    }

    // 字符串分割
    string str_11 = "C++ programming is fun!";
    vector<string> tokens;
    stringstream ss(str_11);
    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    for (const auto& token : tokens) {
        cout << token << endl;
    }
    
    // 字符串替换
    string str_12 = "C++ programming is fun!";
    str_12.replace(4, 9, "is");
    cout << str_12 << endl;

    // 字符串遍历每一个字符
    string str_13 = "C++ programming is fun!";
    for (char c : str_13) {
        cout << c << " ";
    }
    cout << endl;
    
    // 字符串转换成字符数组
    string str_14 = "C++ programming is fun!";
    const char* str_c14 = str_14.c_str();
    cout << str_c14 << endl;
    return 0;
}