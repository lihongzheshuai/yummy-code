/**
 * 题目: 【GESP】C++四级真题 luogu-B3959 [GESP202403 四级] 做题
 * 题号: B3959
 * 归属: GESP4级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b3959/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

// 存储每套题单的题目数量，最大长度为1000005
int ary[1000005];
int main() {
    // 输入题单数量n
    int n;
    std::cin >> n;

    // 输入每套题单的题目数量
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }

    // 将题单按题目数量从小到大排序
    std::sort(ary, ary + n);

    // days记录可以坚持的天数
    int days = 0;

    // 遍历每套题单
    for (int i = 0; i < n; i++) {
        // 如果当前题单的题目数量大于等于需要做的题目数(days+1)
        // 则可以用这套题单完成当天的任务
        if (ary[i] >= days + 1) {
            days++;
        }
    }

    // 输出最终可以坚持的天数
    std::cout << days;
    return 0;
}
