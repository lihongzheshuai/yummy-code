#include <algorithm>
#include <iostream>

// P14357 [CSP-J 2025] 拼数
// 题目要求：从给定字符串中选出所有数字，拼成一个最大的正整数。
// 解题思路：贪心策略。为了使拼成的整数最大，我们应该尽可能让高位（左边）的数字更大。
// 因此，我们将字符串中所有的数字提取出来，然后按从大到小的顺序排列，即可得到最大整数。

int main() {
    std::string s;
    std::cin >> s;  // 输入包含字母和数字的字符串 s
    std::string ans;
    // 遍历字符串 s，筛选出所有的数字字符
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];  // 将数字字符加入到答案字符串中
        }
    }
    // 使用 std::sort 对提取出的数字进行降序排序
    // std::greater<int>() 指定排序规则为从大到小
    std::sort(ans.begin(), ans.end(), std::greater<int>());
    std::cout << ans << std::endl;  // 输出最终拼接成的最大整数
    return 0;
}