/**
 * 题目: 【CSP】CSP-J 2020真题 | 直播获奖 luogu-P7072 （适合GESP四级及以上考生练习）
 * 题号: P7072
 * 归属: GESP4级
 * 博客: https://www.coderli.com/csp-j-2020-p7072/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

int bucket[605]; // 定义一个足够装下 0-600 各分数的桶数组，初始默认全为 0

int main() {
    int n, w;
    std::cin >> n >> w;

    for (int p = 1; p <= n; p++) {
        int score;
        std::cin >> score;

        // 步骤 1：把当前成绩装入对应的桶里，也就是该分数的人数加 1
        bucket[score]++;

        // 步骤 2：算出当前的计划获奖人数
        // 注意仅使用整型计算，先乘后除防止浮点误差且实现向下取整
        int plan_num = std::max(1, p * w / 100);

        // 步骤 3：从最高分 600 向下查找分数线
        int sum = 0; // 累计已统计的高分人数
        for (int i = 600; i >= 0; i--) {
            sum += bucket[i]; // 将该分数段的人数加入总计

            // 如果累计的优秀人数已经达到或超过了目标获奖人数
            if (sum >= plan_num) {
                std::cout << i << " "; // 当前遍历到的分数就是我们需要找的分数线
                break;                 // 找到即可停止循环，处理下一个
            }
        }
    }

    std::cout << std::endl; // 最后输出换行以规范格式
    return 0;
}
