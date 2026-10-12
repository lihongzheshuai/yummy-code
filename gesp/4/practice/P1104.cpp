#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 定义学生信息结构体，封装姓名、出生年月日及输入先后序号
struct Student {
    string name; // 同学姓名
    int year;    // 出生年
    int month;   // 出生月
    int day;     // 出生日
    int id;      // 输入序号（1-based，用于并列时确定先后次序）
};

// 自定义多关键字比较函数
// 比较逻辑优先级：
// 1. 年龄从大到小：出生越早年龄越大，因此年份小的优先排在前面；
// 2. 年份相同时，月份小的优先排在前面；
// 3. 月份相同时，日期小的优先排在前面；
// 4. 年月日均相同时，输入靠后的优先排在前面（即 id 较大的优先）。
bool compareStudent(const Student &a, const Student &b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    if (a.day != b.day) {
        return a.day < b.day;
    }
    return a.id > b.id;
}

int main() {
    int n;
    cin >> n;

    // 声明动态数组存储所有同学信息
    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].year >> students[i].month >> students[i].day;
        students[i].id = i + 1; // 记录输入的先后次序（输入越晚 id 越大）
    }

    // 调用 STL 快速排序算法
    sort(students.begin(), students.end(), compareStudent);

    // 按照排好序的次序依次输出每位同学的姓名
    for (int i = 0; i < n; i++) {
        cout << students[i].name << "\n";
    }

    return 0;
}
