#include <iostream>

std::string array[5][10];
int main() {
    array[0][0] = "XXX";
    array[1][0] = "X.X";
    array[2][0] = "X.X";
    array[3][0] = "X.X";
    array[4][0] = "XXX";

    array[0][1] = "..X";
    array[1][1] = "..X";
    array[2][1] = "..X";
    array[3][1] = "..X";
    array[4][1] = "..X";

    array[0][2] = "XXX";
    array[1][2] = "..X";
    array[2][2] = "XXX";
    array[3][2] = "X..";
    array[4][2] = "XXX";

    array[0][3] = "XXX";
    array[1][3] = "..X";
    array[2][3] = "XXX";
    array[3][3] = "..X";
    array[4][3] = "XXX";

    array[0][4] = "X.X";
    array[1][4] = "X.X";
    array[2][4] = "XXX";
    array[3][4] = "..X";
    array[4][4] = "..X";

    array[0][5] = "XXX";
    array[1][5] = "X..";
    array[2][5] = "XXX";
    array[3][5] = "..X";
    array[4][5] = "XXX";

    array[0][6] = "XXX";
    array[1][6] = "X..";
    array[2][6] = "XXX";
    array[3][6] = "X.X";
    array[4][6] = "XXX";

    array[0][7] = "XXX";
    array[1][7] = "..X";
    array[2][7] = "..X";
    array[3][7] = "..X";
    array[4][7] = "..X";

    array[0][8] = "XXX";
    array[1][8] = "X.X";
    array[2][8] = "XXX";
    array[3][8] = "X.X";
    array[4][8] = "XXX";

    array[0][9] = "XXX";
    array[1][9] = "X.X";
    array[2][9] = "XXX";
    array[3][9] = "..X";
    array[4][9] = "XXX";

    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << array[i][str[j] - '0'];
            if (j != n - 1) {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    return 0;
}