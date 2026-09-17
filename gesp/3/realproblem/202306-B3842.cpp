/**
 * 题目: 【GESP】C++三级真题 luogu-B3842 [GESP202306 三级] 春游
 * 题号: B3842
 * 归属: GESP3级 (202306认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3842/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量n表示学生总数，m表示报数次数
    int m, n;
    std::cin >> n >> m;

    // n_ary数组记录每个编号是否出现过，初始化为0
    int n_ary[n] = {0};
    // m_ary数组存储所有报出的编号
    int m_ary[m];

    // 读取所有报出的编号
    for (int i = 0; i < m; i++) {
        std::cin >> m_ary[i];
    }

    // 初始化n_ary数组为0，表示所有编号都未出现
    for (int i = 0; i < n; i++) {
        n_ary[i] = 0;
    }

    // 遍历所有报出的编号，将对应位置标记为1
    for (int i = 0; i < m; i++) {
        n_ary[m_ary[i]] = 1;
    }

    // flag表示是否所有学生都到齐
    bool flag = true;

    // 遍历n_ary数组，输出未出现的编号
    for (int i = 0; i < n; i++) {
        if (n_ary[i] == 0) {
            std::cout << i << " ";
            flag = false;
        }
    }

    // 如果所有学生都到齐，输出总人数n
    if (flag) {
        std::cout << n;
    }
    return 0;
}
