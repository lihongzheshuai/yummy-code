/**
 * 题目: 【GESP】C++三级练习 luogu-B2114 配对碱基链
 * 题号: B2114
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2114/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
#include<string>

int main(){
    // 声明输入字符串变量
    std::string str;
    // 从标准输入读取DNA序列
    std::cin>>str;
    // 创建结果字符串，初始化为相同长度的空字符串
    std::string r_str = std::string(str.size(), '\0');
    // 遍历输入字符串的每个字符
    for(int i = 0; i < str.size(); i++){
        // 根据碱基配对规则进行转换
        // T配对A
        if (str[i] == 'T') {
            r_str[i] = 'A';
        }
        // A配对T
        else if(str[i] == 'A') {
            r_str[i] = 'T';
        }
        // G配对C
        else if(str[i] == 'G') {
            r_str[i] = 'C';
        }
        // C配对G
        else if(str[i] == 'C') {
            r_str[i] = 'G';
        }
    }
    // 输出互补碱基链
    std::cout<<r_str;
    return 0;
}
