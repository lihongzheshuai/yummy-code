#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> mp;

    // 1. 插入元素
    mp[3] = "C";                   // 用下标插入，如果 key=3 不存在，会新建并赋值
    mp.insert({1, "A"});           // insert 插入
    mp.insert(std::make_pair(2,"B"));

    // 2. 遍历元素（有序，按 key 从小到大）
    std::cout << "map（有序）：\n";
    for (auto &p : mp) {
        std::cout << p.first << " -> " << p.second << "\n";
    }

    // 3. 查找元素
    // ❌ mp[2] = ... 如果 key=2 不存在，会自动插入一个空 value
    // ✅ 用 find 查找更安全
    auto it = mp.find(2);
    if (it != mp.end()) {
        std::cout << "找到 key=2，value=" << it->second << "\n";
    }

    // 4. 删除元素
    mp.erase(3);
    std::cout << "删除 key=3 后，map 大小: " << mp.size() << "\n\n";
}