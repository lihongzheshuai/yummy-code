/**
 * 题目: 【GESP】C++三级、四级练习 luogu-P1597 语句解析-系列题目4
 * 题号: P1597
 * 归属: GESP3级
 * 解法: 解法 5 / 共 5 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-p1597-4/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

// 定义全局变量map，用于存储变量名和对应的值
std::unordered_map<std::string, std::string> v_map;

/**
 * 查找变量的值
 * @param v_name 变量名
 * @return 如果变量存在返回其值，否则返回"0"
 */
std::string find_v_value(std::string v_name) {
    // 如果变量不存在，返回默认值"0"
    if (v_map.find(v_name) == v_map.end()) {
        return "0";
    }
    // 返回变量对应的值
    return v_map[v_name];
}

/**
 * 从字符串中获取等号右边的数值
 * @param str 输入的PASCAL代码字符串
 * @param start 等号的位置
 * @return 等号右边的数值
 */
std::string get_value(std::string str, int& start) {
    // 从start位置开始查找分号的位置
    int end = (int)str.find(';', start);
    // 截取等号到分号之间的子串并转换为整数返回
    std::string r_val = str.substr(start, end - start);
    start = end;
    // 如果是数字直接返回，否则查找变量值
    if (isdigit(r_val[0])) {
        return r_val;
    } else {
        return find_v_value(r_val);
    }
}

/**
 * 获取变量名
 * @param str 输入的PASCAL代码字符串
 * @param start 开始位置
 * @return 变量名
 */
std::string get_v_name(std::string str, int& start) {
    // 查找冒号位置
    int end = (int)str.find(':', start);
    // 截取变量名部分
    std::string result = str.substr(start, end - start);
    start = end;
    return result;
}

/**
 * 设置变量值
 * @param v_name 变量名
 * @param v_val 变量值
 */
void set_v_value(std::string v_name, std::string v_val) {
    // 将变量名和值存入map中
    v_map[v_name] = v_val;
}

/**
 * 打印变量值
 * @param v_name 变量名，默认为空字符串
 */
void print_v_values(std::string v_name = "") {
    if (v_name.empty()) {
        // 如果未指定变量名，打印所有变量的值
        for (auto it = v_map.begin(); it != v_map.end(); it++) {
            std::cout << it->second << " ";
        }
    } else {
        // 打印指定变量的值
        std::cout << v_map[v_name] << " ";
    }
}

int main() {
    // 读取输入字符串
    std::string str;
    std::cin >> str;

    // 定义变量名和值的索引
    int v_name_idx = 0;
    int val_idx = 0;

    // 解析输入字符串
    while (v_name_idx < str.length() && val_idx < str.length()) {
        // 获取变量名
        std::string v_name = get_v_name(str, v_name_idx);
        // 跳过":="
        val_idx = v_name_idx + 2;
        // 获取变量值
        std::string v_val = get_value(str, val_idx);
        // 设置变量值
        set_v_value(v_name, v_val);
        // 移动到下一个语句
        v_name_idx = val_idx + 1;
    }

    // 按顺序打印a、b、c的值
    print_v_values("a");
    print_v_values("b");
    print_v_values("c");
    return 0;
}
