/**
 * 题目: 【CSP】CSP-X 2018真题 | 统计成绩 luogu-B4074 （适合GESP二级及以上考生练习）
 * 题号: B4074
 * 归属: GESP2级
 * 博客: https://www.coderli.com/csp-x-2018-b4074/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // 四个等级的计数器：优秀、良好、及格、不及格
    int excellent = 0, good = 0, pass = 0, fail = 0;

    for (int i = 0; i < n; i++) {
        int score;
        std::cin >> score;

        // 从高到低依次判断等级
        if (score >= 90) {
            excellent++;
        } else if (score >= 80) {
            good++;
        } else if (score >= 60) {
            pass++;
        } else {
            fail++;
        }
    }

    std::cout << excellent << std::endl;
    std::cout << good << std::endl;
    std::cout << pass << std::endl;
    std::cout << fail << std::endl;

    return 0;
}
