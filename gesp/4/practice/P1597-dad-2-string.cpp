#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    int a = 0, b = 0, c = 0;
    std::string v_name = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '=') {
            int spe_idx = (int)str.find(';', i);
            if (isdigit(str[i + 1])) {
                int value = stoi(str.substr(i + 1, spe_idx - i - 1));
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
            i = spe_idx;
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