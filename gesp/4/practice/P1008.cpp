/**
 * 题目: 【NOIP】1998真题解析 luogu-P1008 三连击 | GESP三、四级以上可练习
 * 题号: P1008
 * 归属: GESP4级
 * 博客: https://www.coderli.com/noi-p-1998-luogu-p1008/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstring>
#include <iostream>

// 全局数组，用于统计数字 1~9 在分离出的数位中出现的次数
int n[10];

// 校验一个三位数 x 的每一位是否合法（不能有 0 且不能与已有数字重复）
bool checkNum(int x) {
    int a = x / 100;         // 取百位
    int b = (x / 10) % 10;   // 取十位
    int c = x % 10;          // 取个位

    // 题目要求由 1~9 组成，不包含 0
    if (a == 0 || b == 0 || c == 0) {
        return false;
    }

    // 对应数字记录出现次数加一次
    n[a]++;
    n[b]++;
    n[c]++;

    // 如果任何一个数字出现的次数大于 1，说明有重复，不符合题意
    // 注意：这里的 n 数组是全局共享的，所以也会和另外两个数字一起累计校验
    if (n[a] > 1 || n[b] > 1 || n[c] > 1) {
        return false;
    }

    // 验证通过
    return true;
}

int main() {
    // 最小合法数字为 123，最大的数乘 3 不能超过三位数所以上限是 999 / 3 = 333
    // 在这个范围内进行暴力枚举最小的三位数
    for (int i = 123; i <= 333; i++) {
        int s = i * 2;  // 按比例 1:2 计算出第二个三位数
        int t = i * 3;  // 按比例 1:3 计算出第三个三位数

        // 分别验证 i, s, t，判断 9 个数位是否刚好填满 1~9
        // 注意：C++ 中 && 具有短路特性，左侧若不合法（返回 false），右侧不会继续执行
        // 这样不仅提升了效率，且外层的 memset 会确保数组状态每轮都被重置
        if (checkNum(i) && checkNum(s) && checkNum(t)) {
            std::cout << i << " " << s << " " << t << std::endl;
        }

        // 每次枚举完不论成功与否，都要清空统计数组以便下一轮检测
        memset(n, 0, sizeof(n));
    }

    return 0;
}
