/**
 * 题目: 【GESP】C++三级真题 luogu-B4039 [GESP202409 三级] 回文拼接
 * 题号: B4039
 * 归属: GESP3级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4039/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取测试用例数量
    int n;
    std::cin >> n;
    // 处理每个测试用例
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        // 如果字符串长度小于4，不可能由两个长度至少为2的回文串组成
        if (str.length() < 4) {
            std::cout << "No" << std::endl;
            continue;
        }
        bool flag = true;
        // 遍历所有可能的分割点
        for (int j = 1; j < str.length() - 1; j++) {
            flag = true;
            // 分割字符串为两部分
            std::string f_str = str.substr(0, j);
            std::string s_str = str.substr(j, str.length() - j);
            // 检查第一部分是否为回文串
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
            // 如果第一部分是回文串，检查第二部分
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
            // 如果两部分都是回文串且长度都大于等于2
            if (flag && f_str.length() >= 2 && s_str.length() >= 2) {
                std::cout << "Yes" << std::endl;
                break;
            }
            flag = false;
        }

        if (!flag) {
            std::cout << "No" << std::endl;
        }
    }
}
