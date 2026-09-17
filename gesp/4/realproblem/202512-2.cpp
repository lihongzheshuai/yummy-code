#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * GESP 2025年12月 四级编程题 T2: 优先购买
 *
 * 题目核心：
 * 小 A 有 M 元预算，商店有 N 个商品。
 * 每个商品有：名字 S，价格 P，优先级 V。
 *
 * 购买策略（优先级从高到低）：
 * 1. 优先买优先级最高（V 越小优先级越高）的。
 * 2. 优先级相同时，买价格最低的。
 * 3. 优先级和价格都相同时，买名字字典序最小的。
 *
 * 最终输出：所有购买商品的名字，按字典序排列。
 */

struct Item {
    std::string name;
    int price;
    int priority;
};

// 购买排序规则：优先级 -> 价格 -> 名字
bool compareItems(const Item& a, const Item& b) {
    if (a.priority != b.priority) {
        return a.priority < b.priority;  // V 越小越高
    }
    if (a.price != b.price) {
        return a.price < b.price;  // 价格越低越优先
    }
    return a.name < b.name;  // 字典序越小越优先
}

int main() {
    int m, n;
    // 读取预算 M 和商品数量 N
    std::cin >> m >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].name >> items[i].price >> items[i].priority;
    }

    // 1. 按照购买策略对所有商品进行排序
    std::sort(items.begin(), items.end(), compareItems);

    std::vector<std::string> bought_items;

    // 2. 模拟购买过程
    for (int i = 0; i < n; i++) {
        if (m >= items[i].price) {
            // 买得起就买
            m -= items[i].price;
            bought_items.push_back(items[i].name);
        }
    }

    // 3. 将购买的商品按名字字典序排序
    std::sort(bought_items.begin(), bought_items.end());

    // 4. 输出结果
    for (const auto& name : bought_items) {
        std::cout << name << std::endl;
    }

    return 0;
}
