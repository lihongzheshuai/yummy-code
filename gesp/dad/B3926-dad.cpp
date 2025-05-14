#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    for (int i = 0; i < n; i++) {
        std::string str;
        // std::cin >> str;
        getline(std::cin, str);
        std::size_t first_blank_idx = str.find(" ");
        std::size_t second_blank_idx = str.find(" ", first_blank_idx + 1);
        std::size_t question_idx = str.find("?");
        std::string big_unit = str.substr(
            first_blank_idx + 1, second_blank_idx - first_blank_idx - 1);
        std::string small_unit =
            str.substr(question_idx + 2, str.length() - question_idx - 2);
        int first_num = std::stoi(str.substr(0, first_blank_idx));
        int second_num;
        if (big_unit == "km" || big_unit == "kg") {
            if (small_unit == "m" || small_unit == "g") {
                second_num = first_num * 1000;
            } else if (small_unit == "mm" || small_unit == "mg") {
                second_num = first_num * 1000 * 1000;
            }
        } else if (big_unit == "m" || big_unit == "g") {
            second_num = first_num * 1000;
        }
        std::cout << first_num << " " << big_unit << " " << "=" << " "
                  << second_num << " " << small_unit << std::endl;
    }
    return 0;
}