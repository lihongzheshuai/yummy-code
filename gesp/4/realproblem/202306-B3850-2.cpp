/**
 * 题目: 【GESP】C++四级真题 luogu-B3850 [GESP202306 四级] 幸运数
 * 题号: B3850
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3850/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

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
 * @param num 待判断的数字
 * @return true表示是幸运数，false表示不是幸运数
 * 判断规则：
 * 1. 将数字转换为字符串处理
 * 2. 对奇数位（从右往左，从0开始）进行变换
 * 3. 计算所有位数字之和
 * 4. 判断和是否是8的倍数
 */
bool is_lucky_num(long long num) {
    // 将数字转换为字符串便于处理
    std::string num_str = std::to_string(num);
    // 记录所有位数字之和
    int sum = 0;
    // 从右往左遍历每一位
    for (int i = 0; i < num_str.length(); i++) {
        // 处理奇数位（从右往左数，从0开始）
        if (i % 2 == 0) {
            // 将字符转换为数字
            int c_num = num_str[num_str.length() -1 -i] - '0';
            // 进行变换
            c_num = trans_num(c_num);
            // 将变换后的数字转回字符
            num_str[num_str.length() -1 -i] = char(c_num + '0');
        }
        // 累加当前位的数字
        sum += num_str[num_str.length() -1 -i] - '0';
    }
    // 判断和是否是8的倍数
    if (sum % 8 == 0) {
        return true;
    }
    return false;
}

int main() {
    // 读入待处理的数字个数
    int n;
    std::cin >> n;
    // 循环处理每个数字
    for (int i = 0; i < n; i++) {
        // 读入当前要判断的数字
        long long number;
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
