#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string str;
    std::cin >> str;
    int a = 0, b = 0, c = 0;
    std::string v_name = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '=') {
            if (isdigit(str[i + 1])) {
                if (v_name == "a") {
                    a = str[i + 1] - '0';
                } else if (v_name == "b") {
                    b = str[i + 1] - '0';
                } else {
                    c = str[i + 1] - '0';
                }
            } else {
                if (str[i + 1] == 'a') {
                    if (v_name == "b") {
                        b = a;
                    }
                    if (v_name == "c") {
                        c = a;
                    }
                } else if (str[i + 1] == 'b') {
                    if (v_name == "a") {
                        a = b;
                    }
                    if (v_name == "c") {
                        c = b;
                    }
                } else {
                    if (v_name == "b") {
                        b = c;
                    }
                    if (v_name == "a") {
                        a = c;
                    }
                }
            }
            i += 2;
        } else {
            if (str[i] != ':') {
                v_name = str[i];
            } else {
                continue;
            }
        }
    }

    std::cout << a << " " << b << " " << c;
    return 0;
}