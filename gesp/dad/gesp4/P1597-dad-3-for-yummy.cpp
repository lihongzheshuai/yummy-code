#include <iostream>

std::string v_name[30];
std::string v_value[30];

int is_var_exist(std::string name) {
    for (int i = 0; i < 30; i++) {
        if (v_name[i] == name) {
            return i;
        }
    }
    return -1;
}

std::string find_value(std::string name) {
    for (int i = 0; i < 30; i++) {
        if (v_name[i] == name) {
            return v_value[i];
        }
    }
    return "0";
}

std::string get_value(std::string str) {
    // 数字值
    if (str[0] >= '0' && str[0] <= '9') {
        return str;
    }
    // 变量值
    return find_value(str);
}

int main() {
    std::string str;
    std::cin >> str;
    int ary_idx = 0;
    int f_idx = 0;
    // a:=3;bc:=45;c:=a;a:=4;b:=ca;
    while (f_idx < str.length()) {
        int t_idx = str.find(":", f_idx);
        std::string t_name_str = str.substr(f_idx, t_idx - f_idx);
        int is_exist = is_var_exist(t_name_str);
        if (is_exist == -1) {
            v_name[ary_idx] = t_name_str;
            f_idx = t_idx + 2;
            t_idx = str.find(";", f_idx);
            std::string v_str = str.substr(f_idx, t_idx - f_idx);
            v_value[ary_idx] = get_value(v_str);
            f_idx = t_idx + 1;
            ary_idx++;
        } else {
            f_idx = t_idx + 2;
            t_idx = str.find(";", f_idx);
            std::string v_str = str.substr(f_idx, t_idx - f_idx);
            v_value[is_exist] = get_value(v_str);
            f_idx = t_idx + 1;
        }

    }

    for (int i = 0; i < ary_idx; i++) {
        std::cout << v_name[i] << " " << v_value[i] << "\n";
    }
    return 0;
}