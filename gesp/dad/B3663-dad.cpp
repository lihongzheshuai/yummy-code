#include <iostream>
#include <string>

int main() {
    std::string str;
    getline(std::cin, str);
    int count = 0;
    for (int i = 0; i < str.length(); ) {
        if (str.substr(i,5) == "luogu") {
            count++;
            i += 5;
        } else {
            i++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}