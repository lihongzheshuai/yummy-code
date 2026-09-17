/**
 * 题目: 【GESP】C++三级练习 luogu-B2112 石头剪子布
 * 题号: B2112
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2112/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取游戏次数
    int n;
    std::cin >> n;
    // 循环处理每一次游戏
    for (int i = 0; i < n; i++) {
        // 定义两个字符串变量存储两位玩家的选择
        std::string str_1;
        std::string str_2;
        // 读取两位玩家的选择
        std::cin >> str_1 >> str_2;
        // 判断Player1选择石头的情况
        if (str_1 == "Rock") {
            if (str_2 == "Paper") {          // Player2选择布，Player2获胜
                std::cout << "Player2" << std::endl;
            } else if (str_2 == "Scissors") { // Player2选择剪刀，Player1获胜
                std::cout << "Player1" << std::endl;
            } else {                          // Player2也选择石头，平局
                std::cout << "Tie" << std::endl;
            }
        }
        // 判断Player1选择布的情况
        else if (str_1 == "Paper") {
            if (str_2 == "Rock") {           // Player2选择石头，Player1获胜
                std::cout << "Player1" << std::endl;
            } else if (str_2 == "Scissors") { // Player2选择剪刀，Player2获胜
                std::cout << "Player2" << std::endl;
            } else {                          // Player2也选择布，平局
                std::cout << "Tie" << std::endl;
            }
        }
        // Player1选择剪刀的情况
        else {
            if (str_2 == "Rock") {           // Player2选择石头，Player2获胜
                std::cout << "Player2" << std::endl;
            } else if (str_2 == "Paper") {   // Player2选择布，Player1获胜
                std::cout << "Player1" << std::endl;
            } else {                          // Player2也选择剪刀，平局
                std::cout << "Tie" << std::endl;
            }
        }
    }
    return 0;
}
