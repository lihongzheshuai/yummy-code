/**
 * 题目: 【GESP】C++三级真题 luogu-B3843 [GESP202306 三级] 密码合规
 * 题号: B3843
 * 归属: GESP3级 (202306认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3843/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取输入字符串
    std::string input;
    getline(std::cin, input);

    // 用于存储分割后的密码
    int count = 0;
    std::string cur_pwd;
    std::string str_ary[100] = {""};
    int ary_len = 0;

    // 按逗号分割输入字符串
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ',') {
            cur_pwd = input.substr(i - count, count);
            str_ary[ary_len] = cur_pwd;
            ary_len++;
            count = 0;
        } else {
            count++;
        }
        // 处理最后一个密码
        if (i == input.length() - 1) {
            cur_pwd = input.substr(i - count + 1, count);
            str_ary[ary_len] = cur_pwd;
            ary_len++;
        }
    }

    // 遍历检查每个密码
    for (int i = 0; i < ary_len; i++) {
        bool flag = true;
        std::string cur = str_ary[i];

        // 检查密码长度
        if (cur.length() < 6 || cur.length() > 12) {
            flag = false;
            continue;
        }

        // 记录密码包含的字符类型
        int type[4] = {0}; // 0:小写字母 1:大写字母 2:数字 3:特殊字符

        // 遍历密码中的每个字符
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
                // 包含非法字符
                flag = false;
                break;
            }
        }

        if (!flag) {
            continue;
        }

        // 统计字符类型数量
        int sum = 0;
        for (int k = 0; k < 3; k++) {
            sum += type[k];
        }

        // 检查是否满足字符类型要求
        if (sum < 2 || type[3] == 0) {
            flag = false;
            continue;
        }

        // 输出合规密码
        std::cout << cur << std::endl;
    }
    return 0;
}
