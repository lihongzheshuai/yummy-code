/**
 * 题目: 【CSP】CSP-J 2019 江西真题 | 面积 luogu-P5681 （适合GESP一级、二级考生练习）
 * 题号: P5681
 * 归属: GESP1级
 * 博客: https://www.coderli.com/csp-j-2019-p5681/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 关键点：用 long long 声明变量，防止相乘时结果溢出 int 的范围
    long long a, b, c;

    // 输入边长数据
    std::cin >> a >> b >> c;

    // 计算面积并比较。因为 a, b, c 都是 long long，相乘的结果也会自动使用 64 位无损保存
    long long area_alice = a * a;
    long long area_bob = b * c;

    // 若正方形面积"大"则输出 Alice，否则输出 Bob
    if (area_alice > area_bob) {
        std::cout << "Alice" << std::endl;
    } else {
        std::cout << "Bob" << std::endl;
    }

    return 0;
}
