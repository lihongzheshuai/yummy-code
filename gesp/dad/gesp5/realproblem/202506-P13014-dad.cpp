#include <iostream>

// a数组用于标记数字是否存在。题目保证 1 <= ai <= 1000，
// 所以我们可以用一个大小为1005的数组来记录每个数字是否出现过。
int a[1005];

// 求最大公因数（Greatest Common Divisor）的函数
// 使用辗转相除法（欧几里得算法）
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, q;
    // 输入n（数字个数）和q（询问组数）
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        // 标记数字num出现过。
        // 因为 gcd(x, x, y) = gcd(x, y)，重复的数字不影响最大公因数的结果，
        // 所以我们只需要记录哪些数字出现过，不需要记录出现的次数。
        a[num] = 1;
    }

    // 处理每一组询问
    // i 表示当前询问增加的数值，题目中询问是 a_j + i
    for (int i = 1; i <= q; i++) {
        int cur_gcd = -1;  // 用于存储当前计算出的最大公因数

        // 遍历所有可能的数值（1到1000）
        // 因为 ai 的范围很小，我们可以直接遍历数值范围
        for (int j = 1; j <= 1000; j++) {
            // 如果数值 j 在原数组中存在
            if (a[j] == 1) {
                if (cur_gcd == -1) {
                    // 如果是第一个遇到的数，直接作为当前的 GCD
                    cur_gcd = j + i;
                } else {
                    // 否则，计算当前 GCD 和 (j + i) 的最大公因数
                    // 更新 cur_gcd
                    cur_gcd = gcd(cur_gcd, j + i);
                }
            }
        }
        // 输出当前询问的答案
        std::cout << cur_gcd << std::endl;
    }
    return 0;
}