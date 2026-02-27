#include <iostream>
using namespace std;

// 分别记录每一站上车人数中 a 的系数和 k(第二站上车的未知人数) 的系数
int upA[25], upK[25];
// 分别记录每一站下车人数中 a 的系数和 k 的系数
int downA[25], downK[25];
// 分别记录每一站开出时车上总人数中 a 的系数和 k 的系数
int totalA[25], totalK[25];

int main() {
    int a, n, m, x;
    if (!(cin >> a >> n >> m >> x)) return 0;

    // 第 1 站：上车 a 人 (1*a + 0*k)，下车 0 人，车上 a 人
    upA[1] = 1;
    upK[1] = 0;
    downA[1] = 0;
    downK[1] = 0;
    totalA[1] = 1;
    totalK[1] = 0;

    // 第 2 站：上车 k 人 (0*a + 1*k)，下车 k 人，车上 a 人
    upA[2] = 0;
    upK[2] = 1;
    downA[2] = 0;
    downK[2] = 1;
    totalA[2] = 1;
    totalK[2] = 0;

    // 从第 3 站开始递推
    for (int i = 3; i < n; i++) {
        // 第 i 站上车人数是前两站上车人数之和
        upA[i] = upA[i - 1] + upA[i - 2];
        upK[i] = upK[i - 1] + upK[i - 2];

        // 第 i 站下车人数等于上一站上车人数
        downA[i] = upA[i - 1];
        downK[i] = upK[i - 1];

        // 此站开出时车上总人数 = 之前的总人数 + 这站上车的 - 这站下车的
        totalA[i] = totalA[i - 1] + upA[i] - downA[i];
        totalK[i] = totalK[i - 1] + upK[i] - downK[i];
    }

    // 第 n 站所有人都下车，开出时人数为 0
    totalA[n] = 0;
    totalK[n] = 0;

    // 终点站（第 n 站）下车的人数 m，恰好等于第 n-1 站开出时的车上人数
    // 即 m = totalA[n-1] * a + totalK[n-1] * k
    // 解方程求 k (其中当 n-1 <= 2 时，totalK 可能为 0，k 可任取，默认置 0 即可)
    int k = 0;
    if (n > 1 && totalK[n - 1] != 0) {
        k = (m - totalA[n - 1] * a) / totalK[n - 1];
    }

    // 求第 x 站开出时车上的人数
    int ans = totalA[x] * a + totalK[x] * k;

    cout << ans << endl;
    return 0;
}
