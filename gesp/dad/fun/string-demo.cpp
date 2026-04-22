#include <cstring>
#include <iostream>
#include <string>

int main() {
    char greeting[7] = {'H', 'e', 'l', 'l', 'o', '!'};

    std::cout << greeting << std::endl;
    char arr[4] = "CSP";
    std::string str = "CSP";

    // 如果我们尝试给它们分别在末尾追加一个字母 J：
    strcat(arr, "JS");  // 操作 ①
    str = str + "J";    // 操作 ②
    std::cout << strlen(arr) << std::endl;
    std::cout << str.length() << std::endl;
    std::cout << arr << std::endl;
    std::cout << str << std::endl;
    return 0;
}