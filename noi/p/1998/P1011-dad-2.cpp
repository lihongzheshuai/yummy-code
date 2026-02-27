#include <iostream>

// upOne, downOne, totalOne 分别用来记录每一站(上车、下车、开出时车上)
// 第一站上车人数 a 的系数
int upOne[25];     // 上车人数中 a 的系数
int downOne[25];   // 下车人数中 a 的系数
int totalOne[25];  // 车上总人数中 a 的系数

// upTwo, downTwo, totalTwo 分别用来记录每一站(上车、下车、开出时车上)
// 第二站上车未知人数 k 的系数
int upTwo[25];     // 上车人数中 k 的系数
int downTwo[25];   // 下车人数中 k 的系数
int totalTwo[25];  // 车上总人数中 k 的系数

int main() {
    int a, n, m, x;
    std::cin >> a >> n >> m >>
        x;  // a: 第一站上车人数, n: 车站总数, m: 终点站下车总人数, x:
            // 要求求出的第x站开出时的人数

    // 初始化第 1 站的情况：
    // 第 1 站上车 a 人 (此时 a 的系数为 1, k 的系数为 0)
    upOne[1] = 1;
    downOne[1] = 0;
    totalOne[1] = 1;  // 开出时车上只有 a 人

    upTwo[1] = 0;
    downTwo[1] = 0;
    totalTwo[1] = 0;

    // 初始化第 2 站的情况：
    // 第 2 站上车人数为 k，下车人数也为 k
    // 因此上车人数中 a 的系数为 0，下车中 a 的系数为
    // 0。总体车上依然等于第一站留下来的 a
    upOne[2] = 0;
    downOne[2] = 0;
    totalOne[2] = 1;

    // 第 2 站上车 k 人，所以 k 的系数为 1；题意说下车人数等于上车人数，因此下车
    // k 的系数也为 1 车上 k 增加 1，又减少 1，所以开出时车上 k 的系数依然是 0
    upTwo[2] = 1;
    downTwo[2] = 1;
    totalTwo[2] = 0;

    // 从第 3 站开始按照题意规则进行递推，直到第 n-1 站
    for (int i = 3; i <= n - 1; i++) {
        // 第一站上车人数“a”部分的系数变化：
        upOne[i] =
            upOne[i - 1] + upOne[i - 2];  // 这一站上车数 = 前两站上车数之和
        downOne[i] = upOne[i - 1];        // 这一站下车数 = 前一站上车数
        totalOne[i] = totalOne[i - 1] + upOne[i] -
                      downOne[i];  // 车上总人数 = 原来的人 + 上车 - 下车

        // 第二站上车未知人数“k”部分的系数变化：
        upTwo[i] = upTwo[i - 1] + upTwo[i - 2];
        downTwo[i] = upTwo[i - 1];
        totalTwo[i] = totalTwo[i - 1] + upTwo[i] - downTwo[i];
    }

    int k;
    // 题目给出第 n 站(终点站)的人全部下车，总人数为 m
    // 这说明第 n-1 站开出时的总人数恰好等于 m
    // 即：totalOne[n-1] * a + totalTwo[n-1] * k = m
    // 判断除数 totalTwo[n - 1] 不为 0，防止运行错误（例如当 n=2 或 n=3
    // 时此除数为 0）
    if (n > 1 && totalTwo[n - 1] != 0) {
        k = (m - totalOne[n - 1] * a) / totalTwo[n - 1];
    } else {
        k = 0;  // 如果除数为 0（本题没这数据），给 k 一个默认值
    }

    // 套用算出的 k，根据第 x 站对应存储的 a 和 k 的系数，计算并输出第 x
    // 站开出时的人数
    int ans = totalOne[x] * a + totalTwo[x] * k;
    std::cout << ans << std::endl;
    return 0;
}