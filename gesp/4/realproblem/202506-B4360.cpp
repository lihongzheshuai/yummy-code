/**
 * 题目: 【GESP】C++四级真题 luogu-B4360 [GESP202506 四级] 画布裁剪
 * 题号: B4360
 * 归属: GESP4级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4360/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义字符串数组存储画布内容，最大支持105行
std::string str_ary[105];

int main() {
    // 声明画布的高度和宽度变量
    int h, w;
    std::cin >> h >> w;

    // 声明裁剪区域的行列范围变量
    int x1, x2, y1, y2;
    std::cin >> x1 >> x2 >> y1 >> y2;

    // 读入画布内容，每行一个字符串
    for (int i = 1; i <= h; i++) {
        std::cin >> str_ary[i];
    }

    // 输出裁剪后的画布内容
    // 外层循环遍历选定的行范围
    for (int i = x1; i <= x2; i++) {
        // 内层循环遍历选定的列范围
        for (int j = y1; j <= y2; j++) {
            // 注意：由于字符串下标从0开始，所以这里需要j-1
            std::cout << str_ary[i][j - 1];
        }
        // 每输出完一行后换行
        std::cout << "\n";
    }
    return 0;
}
