/**
 * 题目: 【GESP】C++五级真题（数论、埃氏筛思想考点） luogu-B3969 [GESP202403 五级] B-smooth 数
 * 题号: B3969
 * 归属: GESP5级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-b3969/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 标记数组：nums[i]=1 表示 i 是 B-smooth 数，反之不是
int nums[1000005];

// 判断 x 是否为质数
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int n, B;
    std::cin >> n >> B;

    int count = 0;                 // 当前 B-smooth 数个数
    for (int i = 2; i <= n; ++i) {
        if (i <= B && is_prime(i)) {
            // i 是 ≤B 的质数，将其倍数全部标记为 B-smooth
            for (int j = i; j <= n; j += i) {
                if (nums[j] == 0) {   // 首次被标记
                    nums[j] = 1;
                    count++;
                }
            }
        }
        if (i > B && is_prime(i)) {
            // i 是 >B 的质数，其倍数都不再是 B-smooth，撤销标记
            for (int j = i; j <= n; j += i) {
                if (nums[j] == 1) {   // 之前被标记过
                    nums[j] = 0;
                    count--;
                }
            }
        }
    }
    // 1 恒为 B-smooth，故结果 +1
    std::cout << count + 1 << std::endl;
    return 0;
}
