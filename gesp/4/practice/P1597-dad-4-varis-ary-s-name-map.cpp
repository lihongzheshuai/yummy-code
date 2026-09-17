#include <cctype>
#include <iostream>
#include <string>
#include <map>

std::map<std::string, std::string> v_map;

std::string find_v_value(std::string v_name) {
    if (v_map.find(v_name) == v_map.end()) {
        return "0";
    }
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
    if (isdigit(r_val[0])) {
        return r_val;
    } else {
        return find_v_value(r_val);
    }
}

std::string get_v_name(std::string str, int& start) {
    int end = (int)str.find(':', start);
    std::string result = str.substr(start, end - start);
    start = end;
    return result;
}

void set_v_value(std::string v_name, std::string v_val) {
    v_map[v_name] = v_val;
}

void print_v_values(std::string v_name = "") {
    if (v_name.empty()) {
        for (auto it = v_map.begin(); it != v_map.end(); it++) {
            std::cout << it->second << " ";
        }
    } else {
        std::cout << v_map[v_name] << " ";
    }
}

int main() {
    std::string str;
    std::cin >> str;
    int v_name_idx = 0;
    int val_idx = 0;
    while (v_name_idx < str.length() && val_idx < str.length()) {
        std::string v_name = get_v_name(str, v_name_idx);
        val_idx = v_name_idx + 2;
        std::string v_val = get_value(str, val_idx);
        set_v_value(v_name, v_val);
        v_name_idx = val_idx + 1;
    }
    print_v_values();
    return 0;
}