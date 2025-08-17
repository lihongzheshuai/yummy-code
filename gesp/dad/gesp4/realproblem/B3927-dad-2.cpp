#include <map>
#include <string>
#include <iostream>
#include <cctype>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::string> dict;
    for (int i = 0; i < n; i++) {
        std::string A, B;
        std::cin >> A >> B;
        dict[A] = B;
    }
    std::string input_str;
    std::cin >> input_str;
    std::string result = "";
    int i = 0;
    while (i < input_str.length()) {
        if (islower(input_str[i])) {
            std::string word = "";
            while (i < input_str.length() && islower(input_str[i])) {
                word += input_str[i];
                i++;
            }
            if (dict.count(word)) {
                result += dict[word];
            } else {
                result += "UNK";
            }
        } else {
            result += input_str[i];
            i++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}