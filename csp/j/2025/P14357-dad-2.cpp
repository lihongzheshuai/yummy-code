#include <algorithm>
#include <iostream>

// P14357 [CSP-J 2025] 拼数 - 解法2：桶排序/计数排序
// 解题思路：
// 由于题目只涉及数字 0-9，我们可以统计每个数字出现的次数。
// 然后按照数字即大小（9到0）的顺序，依次输出对应数量的该数字，即可得到最大整数。
// 这种方法的时间复杂度为 O(|s|)，在数据量非常大时比直接排序 O(|s|log|s|) 更优。

int counts[15];  // 桶数组，counts[i] 表示数字 i 出现的次数
int main() {
    std::string s;
    std::cin >> s;  // 输入字符串
    std::string ans;
    // 遍历字符串 s，统计每个数字字符出现的频率
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            counts[s[i] - '0']++;  // 将字符转换为数字索引，并增加计数
        }
    }
    // 从大到小 (9 -> 0) 遍历所有可能的数字
    for (int i = 9; i >= 0; i--) {
        // 将数字 i 重复添加 counts[i] 次到结果中
        for (int j = 0; j < counts[i]; j++) {
            ans += i + '0';  // 将整数 i 转换回字符形式
        }
    }
    std::cout << ans << std::endl;  // 输出最大整数
    return 0;
}