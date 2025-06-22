#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        if (str.length() < 4) {
            std::cout << "No" << std::endl;
            continue;
        }
        bool flag = true;
        for (int j = 1; j < str.length() - 1; j++) {
            flag = true;
            std::string f_str = str.substr(0, j);
            std::string s_str = str.substr(j, str.length() - j);
            int f_b = 0;
            int f_e = f_str.length() - 1;

            while (f_b < f_e) {
                if (f_str[f_b] != f_str[f_e]) {
                    flag = false;
                    break;
                }
                f_b++;
                f_e--;
            }
            if (flag) {
                int s_b = 0;
                int s_e = s_str.length() - 1;
                while (s_b < s_e) {
                    if (s_str[s_b] != s_str[s_e]) {
                        flag = false;
                        break;
                    }
                    s_b++;
                    s_e--;
                }
            }
            if (flag) {
                std::cout << "Yes" << std::endl;
                break;
            }
        }

        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
    TH