#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> ump;

    // 1. 插入元素
    ump[3] = "C";   // 下标插入
    ump.insert({1, "A"});           // 使用初始化列表插入
    ump.insert(std::make_pair(2, "B")); // 使用make_pair插入

    // 2. 遍历元素（无序，顺序不可预测）
    std::cout << "unordered_map（无序）：\n";
    for (auto &p : ump) {
        std::cout << p.first << " -> " << p.second << "\n";
    }

    // 3. 查找元素
    auto it = ump.find(2);
    if (it != ump.end()) {
        std::cout << "找到 key=2，value=" << it->second << "\n";
    }

    // 4. 删除元素
    ump.erase(3);
    std::cout << "删除 key=3 后，unordered_map 大小: " << ump.size() << "\n";
}