/**
 * 题目: 【GESP】C++四级真题 luogu-B3851 [GESP202306 四级] 图像压缩
 * 题号: B3851
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 2 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3851/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 3, 1, 4, 2};
    std::sort(nums.begin(), nums.end());

    for (int num : nums) {
        std::cout << num << " ";
    }
    return 0;
}
