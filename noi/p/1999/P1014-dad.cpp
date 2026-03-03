#include <iostream>

int main() {
    int n;
    std::cin >> n;  // 读取输入的项数 N

    // 初始化位置为表的第一项，即第 1 行第 1 列 (值为 1/1)
    int row = 1, col = 1;

    // 记录当前的移动状态
    bool row_down = true;   // 是否准备或正在向左下方（行增列减）移动
    bool col_right = true;  // 是否准备改变方向标志位

    // 模拟从第 2 项走到第 N 项的移动过程
    for (int i = 2; i <= n; i++) {
        if (row == 1) {       // 如果当前到达了第一行（上边界）
            if (col_right) {  // 碰到上边界后，需要向右平移一步进入下一条对角线
                col++;        // 向右移动一格
                col_right = false;  // 标记平移结束
                row_down = true;    // 接下来准备沿着对角线向左下方移动
            } else {                // 正在向左下方移动的过程中
                row++;              // 行号增加
                col--;              // 列号减少
                col_right = true;   // 恢复标记，以便之后碰到边界时判定
            }
        } else if (col == 1) {  // 如果当前到达了第一列（左边界）
            if (row_down) {  // 碰到左边界后，需要向下平移一步进入下一条对角线
                row++;       // 向下移动一格
                row_down = false;  // 标记平移结束
                col_right = true;  // 接下来准备沿着对角线向右上方移动
            } else {               // 正在向右上方移动的过程中
                row--;             // 行号减少
                col++;             // 列号增加
            }
        } else {  // 如果当前在中间区域（没有碰到第一行或第一列的边界）
            if (row_down) {  // 正在向左下方移动
                row++;       // 行号增加
                col--;       // 列号减少
            } else {         // 正在向右上方移动
                row--;       // 行号减少
                col++;       // 列号增加
            }
        }
    }

    // 输出第 N 项的结果，格式为：行号/列号（第一行是 1/1, 1/2...
    // 行号即分子，列号即分母）
    std::cout << row << "/" << col << std::endl;
}