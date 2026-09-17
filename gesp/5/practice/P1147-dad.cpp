#include <iostream>

int main() {
    int M;
    std::cin >> M;  // 读取目标和 M
    int l = 1,
        r = 2;  // 初始化左指针 l 和右指针 r，表示当前连续子段的起点和终点
    // (l + r) * (r - l + 1) / 2 是等差数列求和公式，用于计算从 l 到 r
    // 的连续整数和 初始 sum 不需赋值，在循环内部计算
    long long current_sum = 0;  // 使用 long long 避免 sum 溢出
    while (l <= (M + 1) / 2) {  // 循环条件：左端点 l 理论上不会超过
                                // (M+1)/2，因为至少有2个数，如果 l 超过
                                // M/2，最小的两个数之和就可能超过 M 了
        current_sum =
            (long long)(l + r) * (r - l + 1) / 2;  // 计算当前 [l, r] 区间的和
        if (current_sum == M) {
            // 如果当前区间和等于 M，找到一组解
            std::cout << l << " " << r << std::endl;
            l++;  // 左指针右移，寻找下一个可能的解
        } else if (current_sum < M) {
            // 如果当前区间和小于 M，说明需要更大的和，右指针右移扩大区间
            r++;
        } else {  // current_sum > M
            // 如果当前区间和大于 M，说明和太大，左指针右移缩小区间
            l++;
        }
    }
    return 0;
}