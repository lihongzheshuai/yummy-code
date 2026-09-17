#include <iostream>
#include <string>

std::string a_str_array[105];
std::string b_str_array[105];

bool is_lower(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

std::string get_b_str(std::string input) {
    for (int i = 0; i < 105; i++) {
        if (input == a_str_array[i]) {
            return b_str_array[i];
        }
    }
    return "UNK";
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a_str_array[i];
        std::cin >> b_str_array[i];
    }
    std::string input_str;
    std::cin >> input_str;
    std::string output_str = "";
    std::string word = "";
    for (int i = 0; i < input_str.length(); i++) {
        if (is_lower(input_str[i])) {
            word += input_str[i];
        } else {
            if (word.length() > 0) {
                std::string b_str = get_b_str(word);
                output_str += b_str;
                word = "";
            }
            output_str += input_str[i];
        }
    }
    if (word.length() > 0) {
        std::string b_str = get_b_str(word);
        output_str += b_str;
    }
    std::cout << output_str;
    return 0;
}