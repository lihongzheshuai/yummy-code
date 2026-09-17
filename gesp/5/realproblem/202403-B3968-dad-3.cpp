#include <iostream>
#include <algorithm>

struct Student {
    int total = 0;
    int chinese = 0;
    int math = 0;
    int english = 0;
    int id = 0;
    int rank = 0;
    // Student(int id, int chinese, int math, int english) : id(id), chinese(chinese), math(math), english(english), total(chinese + math + english) {}
};

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

bool cmp_id(Student a, Student b) {
    return a.id < b.id;
}

const int MAX_N = 1e4 + 5;
struct Student students[MAX_N];

int main() {

    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int chinese, math, english;
        std::cin >> chinese >> math >> english;
        students[i].chinese = chinese;
        students[i].math = math;
        students[i].english = english;
        students[i].total = chinese + math + english;
        students[i].id = i;
    }
    std::sort(students + 1, students + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            students[i].rank = 1;
            continue;
        }
        if (cmp(students[i], students[i - 1])) {
            students[i].rank = students[i - 1].rank;
        } else {
            students[i].rank = i;
        }
    }
    std::sort(students + 1, students + N + 1, cmp_id);
    for (int i = 1; i <= N; i++) {
        std::cout << students[i].rank << std::endl;
    }
    return 0;
}