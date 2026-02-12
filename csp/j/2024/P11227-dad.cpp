#include <iostream>
#include <set>
#include <string>

// P11227 [CSP-J 2024] 扑克牌
// 题目要求计算还需多少张牌才能凑齐一副52张牌（不含大小王）
// 输入 n 张牌，可能有重复，我们需要统计有多少张**不重复**的牌
// std::set 特性：自动去重，非常适合本题

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::set<std::string> cards;  // 定义一个存储 string 的集合，会自动去重
    for (int i = 0; i < n; i++) {
        std::string card;
        std::cin >> card;
        cards.insert(card);  // 插入元素，如果已存在则不会重复插入
    }

    // std::set 常用操作示例（本题不需要，仅作展示）：
    // if (cards.count("DA")) { ... } // 查找是否存在 "DA"
    // cards.erase("DA"); // 删除 "DA"
    // cout << cards.size(); // 获取元素个数

    // 一副牌总共 52 张，我们手里有 cards.size() 张不同的牌
    // 所以还需要 52 - cards.size() 张
    std::cout << 52 - cards.size() << std::endl;

    return 0;
}