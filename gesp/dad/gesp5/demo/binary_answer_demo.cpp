#include <iostream>     // 输入输出流
#include <vector>       // 使用vector容器
#include <numeric>      // 使用accumulate函数
#include <algorithm>    // 使用max_element函数
using namespace std;

// 判定函数：给定最大子数组和 maxSum，是否能分成 <= m 段
bool check(vector<int>& nums, int m, long long maxSum) {
    long long curSum = 0;   // 当前子数组的和
    int count = 1;          // 至少有一段
    
    for (int num : nums) {  // 遍历数组中的每个元素
        if (curSum + num > maxSum) {  // 如果加入当前数字会超过最大和
            count++;                   // 分段数加1
            curSum = num;              // 新开一段
            
            if (count > m) {
                return false;          // 段数超过m，不可行
            }
        } else {
            curSum += num;             // 当前数字可以加入当前段
        }
    }
    
    return true;            // 分段数未超过m，方案可行
}

int splitArray(vector<int>& nums, int m) {
    // 初始化二分查找的左右边界
    long long left = *max_element(nums.begin(), nums.end());    // 左边界为数组中的最大值
    long long right = accumulate(nums.begin(), nums.end(), 0LL); // 右边界为数组总和
    long long ans = right;  // 初始化答案为右边界

    // 二分查找过程
    while (left <= right) {
        long long mid = left + (right - left) / 2;  // 计算中间值，避免溢出
        if (check(nums, m, mid)) {     // 如果当前最大和可行
            ans = mid;                  // 更新答案
            right = mid - 1;            // 尝试更小的值
        } else {
            left = mid + 1;            // 当前值太小，需要增大
        }
    }
    return ans;             // 返回最终答案
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};  // 测试数组
    int m = 2;                            // 需要分成的段数
    cout << "最小的最大子数组和是: " << splitArray(nums, m) << endl;
    return 0;
}