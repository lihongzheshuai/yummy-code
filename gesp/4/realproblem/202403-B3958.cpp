/**
 * 题目: 【GESP】C++四级真题 luogu-B3958 [GESP202403 四级] 相似字符串
 * 题号: B3958
 * 归属: GESP4级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b3958/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>
#include <string>

// 判断两个字符串是否相似的函数
// 参数：两个待比较的字符串 a 和 b
// 返回值：如果相似返回true，否则返回false
bool is_similar(std::string a, std::string b) {
    // 如果两个字符串完全相同，直接返回true
    if (a == b) {
        return true;
    }

    // 如果两个字符串长度差大于1，说明需要多次操作才能相同，返回false
    if (std::abs((int)(a.length() - b.length())) > 1) {
        return false;
    }

    // 处理两个字符串等长的情况
    if (a.length() == b.length()) {
        int diff = 0;  // 记录不同字符的个数
        // 遍历字符串，统计不同字符的数量
        // 由于两个字符串等长，可以同时遍历比较对应位置字符
        for (int i = 0; i < a.length(); i++) {
            // 如果对应位置字符不同，增加差异计数
            if (a[i] != b[i]) {
                diff++;
            }
        }
        // 如果不同字符超过1个，说明需要多次修改，返回false
        if (diff > 1) {
            return false;
        }
        return true;
    }

    // 处理字符串长度相差1的情况
    // s指向较短的字符串，l指向较长的字符串
    std::string s = a.length() > b.length() ? b : a;
    std::string l = a.length() > b.length() ? a : b;

    int i = 0;  // 短字符串的索引
    int j = 0;  // 长字符串的索引
    int diff = 0;  // 记录不同字符的个数

    // 使用双指针遍历两个字符串
    while (i < s.length() && j < l.length()) {
        if (s[i] != l[j]) {
            diff++;
            // 如果不同字符超过1个，返回false
            if (diff > 1) {
                return false;
            }
            // 长字符串指针前移，相当于删除了长字符串中的一个字符
            j++;
        } else {
            // 字符相同时，两个指针都前移
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    int T;  // 测试用例数量
    std::cin >> T;

    // 处理每组测试用例
    for (int i = 0; i < T; i++) {
        std::string a, b;
        std::cin >> a >> b;

        // 输出判断结果
        if (is_similar(a, b)) {
            std::cout << "similar" << std::endl;
        } else {
            std::cout << "not similar" << std::endl;
        }
    }
    return 0;
}
