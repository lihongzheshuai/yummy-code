/**
 * 题目: 【GESP】C++四级真题 luogu-B3850 [GESP202306 四级] 幸运数
 * 题号: B3850
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3850/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

/**
 * 计算一个数字各位数字之和
 * @param num 待计算的数字
 * @return 各位数字之和
 */
int sum_digit(int num) {
    int sum = 0;  // 存储各位数字之和
    while (num != 0) {
        sum += num % 10;  // 取出最后一位数字并累加
        num /= 10;        // 去掉最后一位数字
    }
    return sum;
}

/**
 * 对数字进行变换处理
 * 将数字乘以7，如果结果大于9，则将各位数字相加直到结果不大于9
 * @param num 待变换的数字
 * @return 变换后的结果（保证结果不大于9）
 */
int trans_num(int num) {
    int sum = num * 7;  // 先将数字乘以7
    while(sum > 9) {    // 如果结果大于9，继续处理
        sum = sum_digit(sum);  // 计算各位数字之和
    }
    return sum;
}

/**
 * 判断一个数是否为幸运数
 * 幸运数的定义：将奇数位的数字进行变换后，所有位数字之和是8的倍数
 * @param num 待判断的数字
 * @return true表示是幸运数，false表示不是幸运数
 */
bool is_lucky_num(long long num) {
    int sum = 0;    // 记录所有位数字之和
    int idx = 0;    // 记录当前处理的是第几位
    while (num != 0) {
        // 取出最后一位数字
        int c_num = num % 10;
        // 如果是奇数位（从右往左数，从0开始），进行变换
        if (idx % 2 == 0) {
            c_num = trans_num(c_num);
        }
        sum += c_num;     // 累加当前位的数字
        num /= 10;        // 去掉最后一位
        idx++;           // 位数加1
    }
    // 判断和是否是8的倍数
    if (sum % 8 == 0) {
        return true;
    }
    return false;
}

int main() {
    int n;  // 待处理的数字个数
    std::cin >> n;
    // 循环处理每个数字
    for (int i = 0; i < n; i++) {
        long long number;  // 当前要判断的数字
        std::cin >> number;
        // 判断并输出结果
        if (is_lucky_num(number)) {
            std::cout << 'T' << "\n";
        } else {
            std::cout << 'F' << "\n";
        }
    }
    return 0;
}
