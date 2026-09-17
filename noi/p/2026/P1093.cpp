/**
 * 题目: 【GESP/CSP练习】GESP四级 / CSP-J 题解：luogu-P1093 [NOIP2007 普及组] 奖学金
 * 题号: P1093
 * 归属: GESP4级
 * 博客: https://www.coderli.com/gesp-4-luogu-p1093-scholarship/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu P1093 [NOIP2007 普及组] 奖学金
 * Algorithm: 结构体与多关键字排序
 * GESP Level: 四级 (CSP-J 基础)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 定义学生结构体，集中封装学号、各科成绩与总分
struct Student {
    int id;       // 学生学号 (1 ~ n)
    int chinese;  // 语文单科成绩
    int math;     // 数学单科成绩
    int english;  // 英语单科成绩
    int total;    // 三科总分
};

// 2. 自定义多关键字比较函数
// 遵循严格弱序规范 (Strict Weak Ordering)，严禁使用 >= 或 <=
bool cmp(const Student &a, const Student &b) {
    // 优先级 1：总分降序 (总分高的排在前面)
    if (a.total != b.total) {
        return a.total > b.total;
    }
    // 优先级 2：若总分相同，语文成绩降序 (语文高的排在前面)
    if (a.chinese != b.chinese) {
        return a.chinese > b.chinese;
    }
    // 优先级 3：若总分和语文成绩均相同，学号升序 (学号小的排在前面)
    return a.id < b.id;
}

// 3. 全局静态数组，避免局部栈溢出与变长数组 (VLA)
const int MAXN = 305;
Student stu[MAXN];

int main() {
    // 基础输入输出流加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    // 读入每个学生的各科成绩并计算总分
    for (int i = 0; i < n; ++i) {
        stu[i].id = i + 1; // 依输入顺序标记学号 1 ~ n
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }

    // 调用 STL 快速排序进行多关键字排布，复杂度 O(n log n)
    sort(stu, stu + n, cmp);

    // 依次输出排名前 5 名学生的学号与总分
    int print_count = min(n, 5);
    for (int i = 0; i < print_count; ++i) {
        cout << stu[i].id << " " << stu[i].total << "\n";
    }

    return 0;
}
