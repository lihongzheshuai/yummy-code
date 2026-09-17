/**
 * 题目: 【GESP】C++三级真题 luogu-B3925 [GESP202312 三级] 小猫分鱼
 * 题号: B3925
 * 归属: GESP3级 (202312认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3925/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量n表示小猫数量，i表示每次扔掉的鱼的数量
    int n, i;
    // 从标准输入读取n和i
    std::cin >> n >> i;
    // 从1开始循环，寻找满足条件的最后一只小猫可能拿的最小鱼数
    for (int j = 1;; j++) {
        // flag标记是否找到满足条件的解
        bool flag = true;
        // result记录当前计算的鱼的数量
        int result = 0;
        // 模拟n只小猫分鱼的过程
        for (int k = 0; k < n; k++) {
            if (k == 0) {
                // 最后一只小猫拿前的情况：初始鱼数 = j * n + i
                result = j * n + i;
                continue;
            }
            // 检查剩余的鱼是否能被(n-1)整除
            if (result % (n - 1) != 0) {
                // 不能整除则当前j值不是解
                flag = false;
                break;
            } else {
                // 计算下一只小猫面对的鱼数
                // 先将鱼平均分成n-1份，再乘以n（因为要分n份），最后加上多余的i条
                result = result / (n - 1) * n + i;
            }
        }
        // 如果找到解，输出结果并退出循环
        if (flag) {
            std::cout << result;
            break;
        } else {
            // 未找到解，继续尝试下一个j值
            continue;
        }
    }
    return 0;
}
