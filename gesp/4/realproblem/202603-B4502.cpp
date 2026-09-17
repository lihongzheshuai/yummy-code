/**
 * 题目: 【GESP】C++四级真题 luogu-B4502, [GESP202603 四级] 礼盒排序
 * 题号: B4502
 * 归属: GESP4级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4502/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

// 1. 定义礼盒结构体，把这件商品所有的考量维度打包在一起
struct Box {
    int id;       // 礼盒的编号
    int total;    // 礼盒商品总价
    int max_val;  // 最贵商品的价格
    int min_val;  // 最便宜商品的价格
};

// 2. 编写灵魂：自定义多条件比较函数
// 返回 true 代表希望 a 排在 b 的前面，返回 false 代表退让
bool cmp(const Box& a, const Box& b) {
    // 规则 1：总价格从小到大
    if (a.total != b.total) {
        return a.total < b.total;
    }
    // 规则 2：总价若相同，最贵的大件越便宜越靠前
    if (a.max_val != b.max_val) {
        return a.max_val < b.max_val;
    }
    // 规则 3：若前两项都相同，看最便宜的小件，越便宜越靠前
    if (a.min_val != b.min_val) {
        return a.min_val < b.min_val;
    }
    // 规则 4：若以上全撞车了，编号小的优先
    return a.id < b.id;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    // 创建有 n 个元素的礼盒大群组
    std::vector<Box> boxes(n);

    // 3. 读取并立刻计算加工数据
    for (int i = 0; i < n; i++) {
        boxes[i].id = i + 1; // 赋编号（注意从 1 开始编号）

        int total = 0;
        int max_v = -1;       // 找最大值，初始化为极小
        int min_v = 1000000;  // 找最小值，初始化为极大

        for (int j = 0; j < k; j++) {
            int price;
            std::cin >> price;
            total += price;
            if (price > max_v) {
                max_v = price;
            }
            if (price < min_v) {
                min_v = price;
            }
        }

        // 把算出来的特征烙印在这个礼盒对应的结构体变量上
        boxes[i].total = total;
        boxes[i].max_val = max_v;
        boxes[i].min_val = min_v;
    }

    // 4. 调用 C++ 排序大招，并挂载自己的判断规则
    std::sort(boxes.begin(), boxes.end(), cmp);

    // 5. 按排序后的顺序，挨个念它们的名字（编号）
    for (int i = 0; i < n; i++) {
        std::cout << boxes[i].id;
        if (i < n - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
