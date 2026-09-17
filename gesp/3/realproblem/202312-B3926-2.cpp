/**
 * 题目: 【GESP】C++三级真题 luogu-B3926 [GESP202312 三级] 单位转换
 * 题号: B3926
 * 归属: GESP3级 (202312认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3926/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取题目数量
    int n;
    std::cin >> n;
    while (n--) {
        // 定义变量存储输入数据
        int f_n, s_n;  // f_n: 第一个数字, s_n: 转换后的数字
        std::string b_u, eq, s_u, q;  // b_u: 大单位, eq: 等号, s_u: 小单位, q: 问号
        // 读取一行输入数据
        std::cin >> f_n >> b_u >> eq >> q >> s_u;

        // 根据单位进行转换计算
        if (b_u == "km" || b_u == "kg") {  // 如果是千米或千克
            if (s_u == "m" || s_u == "g") {  // 转换为米或克
                s_n = f_n * 1000;
            } else {  // 转换为毫米或毫克
                s_n = f_n * 1000 * 1000;
            }
        } else {  // 如果是米或克，转换为毫米或毫克
            s_n = f_n * 1000;
        }

        // 按格式输出结果
        std::cout << f_n << " " << b_u << " " << "=" << " " << s_n << " " << s_u
                  << std::endl;
    }
}
