#include <iostream>
#include <string>

int main() {
    std::string input;
    getline(std::cin, input);
    int count = 0;
    std::string cur_pwd;
    std::string str_ary[100] = {""};
    int ary_len = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            cur_pwd = input.substr(i - count, count);
            str_ary[ary_len] = cur_pwd;
            ary_len++;
            count = 0;
        } else {
            count++;
        }
        if (i == input.length() - 1) {
            cur_pwd = input.substr(i - count + 1, count);
            str_ary[ary_len] = cur_pwd;
            ary_len++;
        }
    }
    for (int i = 0; i < ary_len; i++) {
        bool flag = true;
        std::string cur = str_ary[i];
        if (cur.length() < 6 || cur.length() > 12) {
            flag = false;
            continue;
        }
        int type[4] = {0};
        for (int j = 0; j < str_ary[i].length(); j++) {
            if (cur[j] >= 'a' && cur[j] <= 'z') {
                type[0] = 1;
            } else if (cur[j] >= 'A' && cur[j] <= 'Z') {
                type[1] = 1;
            } else if (cur[j] >= '0' && cur[j] <= '9') {
                type[2] = 1;
            } else if (cur[j] == '!' || cur[j] == '@' || cur[j] == '#' ||
                       cur[j] == '$') {
                type[3] = 1;
            } else {
                flag = false;
                break;
            }
        }
        if (!flag) {
            continue;
        }
        int sum = 0;
        for (int k = 0; k < 3; k++) {
            sum += type[k];
        }
        if (sum < 2 || type[3] == 0) {
            flag = false;
            continue;
        }
        std::cout << cur << std::endl;
    }
    return 0;
}