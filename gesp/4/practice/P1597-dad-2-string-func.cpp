#include <cctype>
#include <iostream>
#include <string>

/**
 * 从字符串中获取等号右边的数值
 * @param str 输入的PASCAL代码字符串
 * @param start 等号的位置
 * @return 等号右边的数值
 */
int get_value(std::string str, int start) {
    // 从start位置开始查找分号的位置
    int end = (int)str.find(';', start);
    // 截取等号到分号之间的子串并转换为整数返回
    // start + 1 跳过等号，end - start - 1 表示子串长度
    return stoi(str.substr(start + 1, end - start - 1));
}

int main() {
    std::string str;
    std::cin >> str;
    int a = 0, b = 0, c = 0;
    std::string v_name = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '=') {
            if (isdigit(str[i + 1])) {
                int value = get_value(str, i);
                if (v_name == "a") {
                    a = value;
                } else if (v_name == "b") {
                    b = value;
                } else {
                    c = value;
                }
            } else {
                if (str[i + 1] == 'a') {
                    if (v_name == "b") {
                        b = a;
                    } else if (v_name == "c") {
                        c = a;
                    }
                } else if (str[i + 1] == 'b') {
                    if (v_name == "a") {
                        a = b;
                    } else if (v_name == "c") {
                        c = b;
                    }
                } else if (str[i + 1] == 'c') {
                    if (v_name == "a") {
                        a = c;
                    } else if (v_name == "b") {
                        b = c;
                    }
                }
            }
            i =  (int)str.find(';', i);
        } else {
            if (str[i] != ':') {
                v_name = str[i];
            } else {
                continue;
            }
        }
    }
    std::cout << a << " " << b << " " << c << std::endl;
    return 0;
}