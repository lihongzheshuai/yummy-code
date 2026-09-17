/**
 * 题目: 【GESP】C++五级真题（结构体排序考点） luogu-B3968 [GESP202403 五级] 成绩排序
 * 题号: B3968
 * 归属: GESP5级 (202403认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-b3968/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 学生结构体：存储成绩、原始序号及排名
struct Student {
    int total;    // 三科总分
    int chinese;  // 语文成绩
    int math;     // 数学成绩
    int english;  // 英语成绩
    int id;       // 原始输入序号（1-based）
    int rank;     // 计算出的最终排名

    // 默认构造函数，全部初始化为0
    Student() : total(0), chinese(0), math(0), english(0), id(0), rank(0) {}

    // 带参构造函数：根据序号和三科成绩初始化，并自动计算总分
    Student(int id, int chinese, int math, int english)
        : id(id), chinese(chinese), math(math), english(english),
          total(chinese + math + english) {}
};

// 排序比较函数：按题目规则降序排列
// 1. 总分高者优先
// 2. 总分相同时，语文+数学总分高者优先
// 3. 仍相同，则语文、数学两科最高分高者优先
// 4. 仍相同，保持原顺序（返回 true 表示不交换）
bool cmp(Student a, Student b) {
    if (a.total != b.total) {
        return a.total > b.total;
    }
    if (a.chinese + a.math != b.chinese + b.math) {
        return a.chinese + a.math > b.chinese + b.math;
    }
    int max_a = std::max(a.chinese, a.math);
    int max_b = std::max(b.chinese, b.math);
    if (max_a != max_b) {
        return max_a > max_b;
    }
    return true;
}

// 按原始序号升序比较，用于最后恢复输入顺序
bool cmp_id(Student a, Student b) {
    return a.id < b.id;
}

// 最大学生数常量，1e4+5 防止越界
const int MAX_N = 1e4 + 5;
// 全局数组，存储所有学生信息
struct Student students[MAX_N];

int main() {
    int N;
    std::cin >> N;  // 读取学生人数

    // 依次读入每位学生的三科成绩，并用带参构造初始化结构体
    for (int i = 1; i <= N; i++) {
        int chinese, math, english;
        std::cin >> chinese >> math >> english;
        Student student(i, chinese, math, english);
        students[i] = student;
    }

    // 按自定义规则降序排序，排名计算基于排序后数组
    std::sort(students + 1, students + N + 1, cmp);

    // 计算并列排名：若当前学生与前一名“相等”（cmp 返回 true），则同排名；否则排名等于当前下标
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            students[i].rank = 1;  // 第一名默认排名 1
            continue;
        }
        if (cmp(students[i], students[i - 1])) {
            // 当前学生“等于”前一名，沿用前一名排名
            students[i].rank = students[i - 1].rank;
        } else {
            // 否则排名等于当前位置
            students[i].rank = i;
        }
    }

    // 按原始输入序号重新排序，恢复输入顺序
    std::sort(students + 1, students + N + 1, cmp_id);

    // 按原始输入顺序输出每位学生的最终排名
    for (int i = 1; i <= N; i++) {
        std::cout << students[i].rank << std::endl;
    }
    return 0;
}
