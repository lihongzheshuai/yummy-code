/**
 * 题目: 【GESP】C++四级真题 luogu-B4558 [GESP202606 四级] 身高体重指数
 * 题号: B4558
 * 归属: GESP4级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4558/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 结构体存储小朋友的编号和 BMI 值
struct Child {
    int id;       // 编号（从 1 开始）
    double bmi;   // 身高体重指数
};

// 自定义比较函数：按 BMI 从高到低排序
bool cmp(const Child &a, const Child &b) {
    return a.bmi > b.bmi;
}

int main() {
    int n;
    std::cin >> n;

    Child children[1005];
    int w[1005];
    double h[1005];

    // 读入体重
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i];
    }
    // 读入身高
    for (int i = 1; i <= n; i++) {
        std::cin >> h[i];
    }

    // 计算每个小朋友的 BMI 并存入结构体
    for (int i = 1; i <= n; i++) {
        children[i].id = i;
        children[i].bmi = w[i] / (h[i] * h[i]);
    }

    // 按 BMI 从高到低排序
    std::sort(children + 1, children + 1 + n, cmp);

    // 输出排序后的编号
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            std::cout << " ";
        }
        std::cout << children[i].id;
    }
    std::cout << std::endl;
    return 0;
}
