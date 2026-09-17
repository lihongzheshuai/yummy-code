/**
 * 题目: 【GESP】C++五级真题（埃氏筛思想考点） luogu-B3929 [GESP202312 五级] 小杨的幸运数
 * 题号: B3929
 * 归属: GESP5级 (202312认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3929/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> square_nums;  // 存放所有 ≥a 的完全平方数（超级幸运数）

// 判断 x 是否为幸运数：只要 x 是某个超级幸运数的倍数即可
bool is_lucky(int x) {
    for (int i = 0; i < square_nums.size(); i++) {
        if (x == square_nums[i] || x % square_nums[i] == 0) {
            return true;  // 找到任一超级幸运数能整除 x，即为幸运数
        }
    }
    return false;  // 没有任何超级幸运数能整除 x，不是幸运数
}

// 对非幸运数 x 进行“幸运化”：返回不小于 x 的最小幸运数
std::string luckyize(int x, int a) {
    // 若 x 本身已是幸运数且 ≥a，直接返回 lucky
    if (is_lucky(x) && x >= a) {
        return "lucky";
    }

    int lucky_num;  // 用于保存幸运化结果
    if (a >= x) {
        // 当 a ≥ x 时，最小幸运数就是 ≥a 的最小完全平方数
        lucky_num = std::pow(std::ceil(std::sqrt(a)), 2);
    } else {
        // 当 x > a 时，找 ≥x 的最小“超级幸运数倍数”
        // 先以第一个超级幸运数为基准，计算其倍数中 ≥x 的最小值
        // 计算 ≥x 的最小“square_nums[0] 的倍数”：
        // 若 x 能被 square_nums[0] 整除，则 x 本身就是该倍数；
        // 否则先求出 x 除以 square_nums[0] 的余数 r = x % square_nums[0]，
        // 再把 x 向上“补齐”到下一个整数倍，即 x + (square_nums[0] - r)。
        // 合并写法：square_nums[0] + x - x % square_nums[0]
        lucky_num = square_nums[0] + x - x % square_nums[0];
        // 再遍历其余超级幸运数，取最小值
        for (int i = 1; i < square_nums.size(); i++) {
            lucky_num = std::min(lucky_num, square_nums[i] + x - x % square_nums[i]);
        }
    }
    return std::to_string(lucky_num);  // 返回字符串形式的幸运化结果
}

int main() {
    int a, N;
    std::cin >> a >> N;  // 读入起始下界 a 和询问次数 N

    // 预处理：把所有 ≥a 的完全平方数加入 square_nums
    for (int i = 1; i <= 1001; i++) {
        if (i * i >= a) {
            square_nums.push_back(i * i);
        }
    }

    // 处理 N 次询问
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;  // 读入待判断/幸运化的数
        std::cout << luckyize(x, a) << std::endl;  // 输出结果
    }

    return 0;
}
