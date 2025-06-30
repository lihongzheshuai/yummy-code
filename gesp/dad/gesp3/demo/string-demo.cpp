#include <iostream>
#include <string>

int main() {
    std::string str = "hello";
    if (str[5] == '11') {
        std::cout << "1" << std::endl;
    }
    else if (str[5] == '\0') {
        std::cout << "2" << std::endl;
    }
    int a = 65;
	std::cout << tolower(a); 
    return 0;
}
