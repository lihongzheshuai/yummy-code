#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

struct color_info {
    int color_num;
    int freq;
};

struct color_info colors[256];

int hexstr_to_int(std::string str) {
    return std::stoi(str, nullptr, 16);
}

std::string int_to_hexstr(int num, int bit) {
    std::stringstream ss;
    ss <<  std::setw(bit) << std::setfill('0') << std::hex << std::uppercase << num;
    return ss.str();
}

bool compare(color_info a, color_info b) {
    return a.freq == b.freq ? a.color_num < b.color_num : a.freq > b.freq;
}

int trans_color(int color_num, struct color_info top_color[16]) {
    int min_diff = 1000000000;
    int min_index = 0;
    for (int i = 0; i < 16; i++) {
        int diff = abs(color_num - top_color[i].color_num);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> colors_vec(n);
    for (int i = 0; i < n; i++) {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < str.length(); j+=2) {
            int color_num = hexstr_to_int(str.substr(j, 2));
            colors_vec[i].push_back(color_num);
            colors[color_num].freq++;
            colors[color_num].color_num = color_num;
        }
    }

    std::sort(colors, colors + 256,compare);

    struct color_info top_color[16];

    for (int i = 0; i < 16; i++) {
        top_color[i] = colors[i];
        std::cout << int_to_hexstr(top_color[i].color_num,2);
    }
    std::cout << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < colors_vec[i].size(); j++) {
            int trans_color_num = trans_color(colors_vec[i][j], top_color);
            std::cout << int_to_hexstr(trans_color_num, 1);
        }
        std::cout << "\n";
    }

    
}