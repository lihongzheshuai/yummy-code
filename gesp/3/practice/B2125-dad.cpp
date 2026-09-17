#include<iostream>
#include<string>

int main() {
    int n;
    std::cin >> n;
    int max = -1;
    std::string max_name;
    for (int i = 0; i < n; i++) {
        int point;
        std::string name;
        std::cin >> point >> name;
        if (point > max) {
            max = point;
            max_name = name;
        }
    }
    std::cout << max_name;
    return 0;
}