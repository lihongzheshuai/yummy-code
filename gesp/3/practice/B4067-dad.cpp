#include <iostream>
#include <string>

int main() {
    std::string line_one[] = {".....", "****.", ".....", "....."};
    std::string line_two[] = {".***.", "****.", "****.", "****."};
    std::string line_three[] = {".***.", "****.", ".....", "....."};
    std::string line_four[] = {".***.", "****.", ".****", "****."};
    std::string line_five[] = {".....", "****.", ".....", "....."};

    int n;
    std::cin >> n;

    std::string n_str = std::to_string(n);
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_one[cur_num];
    }
    std::cout << std::endl;
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_two[cur_num];
    }
    std::cout << std::endl;
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_three[cur_num];
    }
    std::cout << std::endl;
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_four[cur_num];
    }
    std::cout << std::endl;
    for (int i = 0; i < n_str.size(); i++) {
        int cur_num = n_str[i] - '0';
        std::cout << line_five[cur_num];
    }
    return 0;
}