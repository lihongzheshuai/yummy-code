#include <iostream>

// pos 数组用于存储地毯的信息
// pos[i][0], pos[i][1] 分别表示第 i 张地毯左下角的 x, y 坐标
// pos[i][2], pos[i][3] 分别表示第 i 张地毯在 x 轴和 y 轴方向的长度
int pos[10005][4];

int main() {
    int n;  // 地毯的总数 n
    std::cin >> n;

    // 依次读入每张地毯的信息，地毯编号从 1 到 n
    for (int i = 1; i <= n; i++) {
        std::cin >> pos[i][0] >> pos[i][1] >> pos[i][2] >> pos[i][3];
    }

    int x, y;  // 所求地面的点的坐标 (x, y)
    std::cin >> x >> y;

    int ans = -1;  // 记录所求的地毯的编号，如果没有被地毯覆盖则初始化输出 -1

    // 从最后铺设的（也就是最上面的）地毯开始倒序遍历
    // 只要找到第一个覆盖了点 (x, y) 的地毯，那就是覆盖该点的最上面的那张
    for (int i = n; i >= 1; i--) {
        // 判断点 (x, y) 是否在第 i 张地毯的覆盖范围内
        // 即 x 坐标在 [a, a + g] 之间，y 坐标在 [b, b + k] 之间
        if (x >= pos[i][0] && x <= pos[i][0] + pos[i][2] && y >= pos[i][1] &&
            y <= pos[i][1] + pos[i][3]) {
            ans = i;  // 记录答案（即对应的地毯编号）
            break;    // 找到了最上面的那张，直接退出循环
        }
    }

    // 输出结果，若没有地毯覆盖此处则会输出初始化时的 -1
    std::cout << ans << std::endl;

    return 0;
}