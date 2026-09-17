#include <iostream>

// 定义一个足够大的二维数组用于存放魔方阵
int array[25][25];

int main() {
    int n;
    std::cin >> n; // 输入魔方阵的阶数n（n为奇数）

    int mid = n / 2; // 计算中间列的位置
    array[0][mid] = 1; // 将1放在第一行的中间位置

    int num = 2; // 下一个要填入的数字
    int l_n = 0, l_m = mid; // l_n, l_m分别表示上一个数字所在的行和列
    int c_n, c_m; // c_n, c_m用于计算下一个数字应该放置的位置

    // 按照“上右”规则依次填入数字，直到n*n
    while (num <= n * n) {
        // 计算下一个位置：上一行（如果到顶则到最后一行），右一列（如果到最右则到最左）
        c_n = l_n == 0 ? n - 1 : l_n - 1;
        c_m = l_m == n - 1 ? 0 : l_m + 1;

        // 如果该位置还没有填数字
        if (array[c_n][c_m] == 0) {
            array[c_n][c_m] = num; // 填入数字
            num++; // 下一个数字
            l_n = c_n; // 更新上一个数字的位置
            l_m = c_m;
        } else {
            // 如果该位置已经有数字，则下移一格
            c_n = l_n == n - 1 ? 0 : l_n + 1;
            c_m = l_m;
            array[c_n][c_m] = num; // 填入数字
            num++; // 下一个数字
            l_n = c_n; // 更新上一个数字的位置
            l_m = c_m;
        }
    }

    // 输出魔方阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << array[i][j] << " "; // 输出每个元素，空格分隔
        }
        std::cout << "\n"; // 每行结束换行
    }
    return 0;
}