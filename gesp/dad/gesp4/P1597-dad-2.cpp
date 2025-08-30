#include <cctype>  // 用于判断字符是否为数字
#include <iostream>
#include <string>

int main() {
    std::string str;  // 用于存储输入的字符串
    std::cin >> str;

    int a = 0, b = 0, c = 0;  // 用于存储变量a, b, c的值
    std::string v_name = "";  // 用于存储当前变量的名称

    // 遍历输入的字符串
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '=') {  // 遇到等号，判断右边是否为数字
            if (isdigit(str[i + 1])) {
                int j = 1;  // 用于遍历右边的数字
                std::string value_str = "";  // 用于存储右边的数字
                while (str[i + j] != ';') {
                    value_str += str[i + j];
                    j++;
                }
                int value = stoi(value_str);  // 将右边的数字转换为整数
                if (v_name == "a") {  // 若当前变量为a，则将a的值设置为右边的数字
                    a = value;
                } else if (v_name == "b") {  // 若当前变量为b，则将b的值设置为右边的数字
                    b = value;
                } else {  // 若当前变量为c，则将c的值设置为右边的数字
                    c = value;
                }
            } else {  // 若右边不是数字，则判断右边是否为a、b或c
                if (str[i + 1] == 'a') {
                    if (v_name == "b") {  // 若当前变量为b，则将b的值设置为a的值
                        b = a;
                    } else if (v_name == "c") {  // 若当前变量为c，则将c的值设置为a的值
                        c = a;
                    }
                } else if (str[i + 1] == 'b') {
                    if (v_name == "a") {  // 若当前变量为a，则将a的值设置为b的值
                        a = b;
                    } else if (v_name == "c") {  // 若当前变量为c，则将c的值设置为b的值
                        c = b;
                    }
                } else if (str[i + 1] == 'c') {
                    if (v_name == "a") {  // 若当前变量为a，则将a的值设置为c的值
                        a = c;
                    } else if (v_name == "b") {  // 若当前变量为b，则将b的值设置为c的值
                        b = c;
                    }
                }
            }
        } else {  // 若遇到的不是等号，则判断是否为冒号
            if (str[i] != ':') {  // 若不是冒号，则将当前变量的名称设置为该字符
                v_name = str[i];
            } else {  // 若是冒号，则跳过该字符
                continue;
            }
        }
    }

    // 输出变量a, b, c的值
    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}