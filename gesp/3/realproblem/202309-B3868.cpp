/**
 * 题目: 【GESP】C++三级真题 luogu-B3868 [GESP202309 三级] 进制判断
 * 题号: B3868
 * 归属: GESP3级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3868/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取需要处理的数字个数
    int n;
    std::cin >> n;

    // 处理每个输入的数字
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;

        // 初始化结果数组,分别表示二进制、八进制、十进制、十六进制的可能性
        int result[4] = {1, 1, 1, 1};

        // 遍历字符串的每个字符
        for (int j = 0; j < str.length(); j++) {
            // 检查是否可能是二进制数(只能包含0和1)
            if (str[j] > '1') {
                result[0] = 0;
            }
            // 检查是否可能是八进制数(只能包含0-7)
            if (str[j] > '7') {
                result[1] = 0;
            }
            // 检查是否可能是十进制数(只能包含0-9)
            if (str[j] > '9') {
                result[2] = 0;
            }
            // 检查是否可能是十六进制数(只能包含0-9和A-F)
            if (str[j] > 'F') {
                result[3] = 0;
            }
        }

        // 输出结果
        for (int j = 0; j < 4; j++) {
            std::cout << result[j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
