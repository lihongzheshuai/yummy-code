/**
 * 题目: 【GESP】C++四级真题 luogu-B4361 [GESP202506 四级] 排序
 * 题号: B4361
 * 归属: GESP4级 (202506认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4361/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义二维数组存储学生身高和体重信息
// s_ary[i][0]存储身高，s_ary[i][1]存储体重
int s_ary[3005][2];

int main() {
    // 读入学生人数
    int n;
    std::cin >> n;

    // 读入每个学生的身高和体重
    for (int i = 0; i < n; i++) {
        std::cin >> s_ary[i][0] >> s_ary[i][1];
    }

    // 计算需要交换的次数
    int count = 0;
    // 冒泡排序的交换次数计算
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 如果前面的学生身高小于后面的学生
            // 或者身高相同但体重小于后面的学生
            // 则需要进行交换，计数+1
            if (s_ary[i][0] < s_ary[j][0] ||
                (s_ary[i][0] == s_ary[j][0] && s_ary[i][1] < s_ary[j][1])) {
                count++;
            }
        }
    }

    // 输出最少需要的交换次数
    std::cout << count;
    return 0;
}
