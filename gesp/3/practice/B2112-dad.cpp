#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string str_1;
        std::string str_2;
        std::cin >> str_1 >> str_2;
        if (str_1 == "Rock") {
            if (str_2 == "Paper") {
                std::cout << "Player2" << std::endl;
            } else if (str_2 == "Scissors") {
                std::cout << "Player1" << std::endl;
            } else {
                std::cout << "Tie" << std::endl;
            }
        } else if (str_1 == "Paper") {
            if (str_2 == "Rock") {
                std::cout << "Player1" << std::endl;
            } else if (str_2 == "Scissors") {
                std::cout << "Player2" << std::endl;
            } else {
                std::cout << "Tie" << std::endl;
            }
        } else {
            if (str_2 == "Rock") {
                std::cout << "Player2" << std::endl;
            } else if (str_2 == "Paper") {
                std::cout << "Player1" << std::endl;
            } else {
                std::cout << "Tie" << std::endl;
            }
        }
    }
    return 0;
}
