/**
 * 题目: 【GESP】C++四级真题 luogu-B3851 [GESP202306 四级] 图像压缩
 * 题号: B3851
 * 归属: GESP4级 (202306认证真题)
 * 解法: 解法 3 / 共 4 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b3851/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 95}
    };

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // 按成绩降序
    });

    for (const auto& s : students) {
        std::cout << s.name << " " << s.score << std::endl;
    }
    return 0;
}
