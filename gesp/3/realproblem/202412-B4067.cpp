/**
 * 题目: 【GESP】C++三级真题 luogu-B4067 [GESP202412 三级] 打印数字
 * 题号: B4067
 * 归属: GESP3级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4067/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义5个数组存储0-3这4个数字在5x5网格中每一行的显示样式
    std::string line_one[] = {".....", "****.", ".....", "....."};
    std::string line_two[] = {".***.", "****.", "****.", "****."};
    std::string line_three[] = {".***.", "****.", ".....", "....."};
    std::string line_four[] = {".***.", "****.", ".****", "****."};
    std::string line_five[] = {".....", "****.", ".....", "....."};

    // 读入输入的数字
    int n;
    std::cin >> n;

    // 将数字转换为字符串，方便逐位处理
    std::string n_str = std::to_string(n);

    // 按行输出每个数字的显示样式
    // 第一行
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';  // 将字符转换为对应的数字
        std::cout << line_one[cur_num];
    }
    std::cout << std::endl;

    // 第二行
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_two[cur_num];
    }
    std::cout << std::endl;

    // 第三行
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_three[cur_num];
    }
    std::cout << std::endl;

    // 第四行
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_four[cur_num];
    }
    std::cout << std::endl;

    // 第五行
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_five[cur_num];
    }
    return 0;
}
