/**
 * 题目: 【CSP】CSP-J 2020真题 | 优秀的拆分 luogu-P7071 （适合GESP二、三级及以上考生练习）
 * 题号: P7071
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2020-p7071/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // 第一步：如果 n 不能被 2 整除，说明是奇数，不满足题意无法分配。
    if (n % 2 != 0) {
        std::cout << -1 << std::endl;
        return 0; // 直接打断退出
    }

    // 第二步：循环倍增。找到刚好不超过 n 的那个最大的 2 的次幂值
    int power = 2; // 起点最少是 2
    while (power <= n) {
        power *= 2;
    }
    // 循环结束后 power 肯定跑到 n 的上限上面超标了，比如 n=10 就会导致 power 大到了 16。
    // 我们在此回退一档：
    power /= 2;

    // 第三步：拿到的这个最大的 power 开始开动，依次减去符合要求的配额
    while (n > 0) {
        if (n >= power) { // 判断当前的 n 够不够减
            std::cout << power << " "; // 够减必定是要这个权值的，马上输出
            n -= power;                // 目标数字扣掉消耗
        }
        power /= 2; // 不断降档试探！次幂阶梯往下降一等级，例如从 8 砍下来降到去试探 4
    }

    std::cout << std::endl;
    return 0;
}
