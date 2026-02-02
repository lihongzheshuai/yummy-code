#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    int target;
    std::cin >> target;  // 小R的成绩，即第一个输入的成绩

    int rank = 1;
    // 只需要知道有多少人比小R成绩高，就能确定小R是第几名
    // 输入剩下的 n*m - 1 个成绩
    for (int i = 1; i < n * m; ++i) {
        int score;
        std::cin >> score;
        if (score > target) {
            rank++;
        }
    }

    // 题目中座位是按成绩从高到低排列
    // rank 就是小R在排序后的索引（1-based）

    // 计算列号 col
    // 每一列有 n 行，蛇形填数
    // 第 1 列填 1..n 名
    // 第 2 列填 n+1..2n 名
    // ...
    // 所以 col = ceil(rank / n)
    int col = (rank - 1) / n + 1;

    // 计算行号 row
    // 如果 col 是奇数，从上往下填 (1 -> n)
    // 如果 col 是偶数，从下往上填 (n -> 1)

    // 在当前列中的相对位置 (0-based offset for simple math)
    int pos_in_col = (rank - 1) % n;

    int row;
    if (col % 2 != 0) {  // 奇数列：1, 3, 5... 从上往下
        // pos_in_col 0 -> row 1
        // pos_in_col n-1 -> row n
        row = pos_in_col + 1;
    } else {  // 偶数列：2, 4, 6... 从下往上
        // pos_in_col 0 -> row n
        // pos_in_col n-1 -> row 1
        row = n - pos_in_col;
    }

    std::cout << col << " " << row << std::endl;

    return 0;
}
