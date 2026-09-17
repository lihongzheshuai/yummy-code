/**
 * 题目: 【GESP】C++四级真题 luogu-B4069 [GESP202412 四级] 字符排序
 * 题号: B4069
 * 归属: GESP4级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4069/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <map>

// 定义字符串数组，用于存储输入的字符串
std::string str_ary[105];

/**
 * 检查排序后的字符串数组是否满足条件
 * 条件：前一个字符串的最后一个字符不大于后一个字符串的第一个字符
 * @param n 字符串数量
 * @return 是否满足条件
 */
bool check(int n) {
    for (int i = 1; i < n; i++) {
        // 比较相邻字符串的最后一个字符和第一个字符
        if (str_ary[i - 1].back() > str_ary[i].front()) {
            return false;
        }
    }
    return true;
}

int main() {
    // 读入测试用例数量
    int T;
    std::cin >> T;

    // 处理每组测试用例
    while (T--) {
        // 读入字符串数量
        int n;
        std::cin >> n;

        // flag用于标记每个字符串本身是否有序
        bool flag = true;

        // 读入所有字符串并检查每个字符串本身是否有序
        for (int i = 0; i < n; i++) {
            std::cin >> str_ary[i];
            // 使用is_sorted检查字符串本身是否按字典序排序
            if (!is_sorted(str_ary[i].begin(), str_ary[i].end())) {
                flag = false;
            }
        }

        // 对字符串数组进行排序
        std::sort(str_ary, str_ary + n);

        // 输出结果：
        // 1. 每个字符串本身必须有序(flag为true)
        // 2. 排序后的字符串数组必须满足check条件
        if (flag && check(n)) {
            std::cout << "1" << "\n";
        } else {
            std::cout << "0" << "\n";
        }
    }

    return 0;
}
