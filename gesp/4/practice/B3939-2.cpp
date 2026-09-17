/**
 * 题目: 【GESP】C++四级练习 luogu-B3939 [GESP样题 四级] 绝对素数
 * 题号: B3939
 * 归属: GESP4级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3939/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

/**
 * 判断一个数是否为素数
 * @param num 待判断的数字
 * @return true表示是素数，false表示不是素数
 */
bool is_prime_number(int num) {
    bool flag = true;
    // 从2到sqrt(num)遍历，检查是否有因子
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

/**
 * 判断一个数是否为绝对素数
 * 绝对素数：两位数本身是素数，且数字位置对换后仍为素数
 * @param num 待判断的数字
 * @return true表示是绝对素数，false表示不是绝对素数
 */
bool is_abs_prime_number(int num) {
    // 先判断数字本身是否为素数
    bool flag = is_prime_number(num);

    if (flag) {
        // 计算数字位置对换后的新数
        // 例如：13 -> 31
        // num % 10得到个位，乘10后变为十位
        // num / 10得到十位，变为个位
        int alter_num = num % 10 * 10 + num / 10;
        // 判断对换后的数是否为素数
        flag = is_prime_number(alter_num);
    }
    return flag;
}

int main() {
    // 定义区间范围变量
    int A,B;
    // 读入区间范围
    std::cin >> A >> B;
    // 遍历区间内的每个数
    for (int i = A; i <= B; i++) {
        // 如果是绝对素数则输出
        if(is_abs_prime_number(i)) {
            std::cout << i << "\n";
        }
    }
    return 0;
}
