#include <algorithm>
#include <iostream>

struct Student {
    int total;
    int chinese;
    int math;
    int english;
    int id;
    int rank;

    Student() : total(0), chinese(0), math(0), english(0), id(0), rank(0) {}
    Student(int id, int chinese, int math, int english)
        : id(id),
          chinese(chinese),
          math(math),
          english(english),
          total(chinese + math + english) {}
};

const int MAX_N = 1e4 + 5;
struct Student students[MAX_N];

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

int get_rank(int id, int N) {
    for (int i = 1; i <= N; i++) {
        if (students[i].id == id) {
            return students[i].rank;
        }
    }
    return 0;
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        int chinese, math, english;
        std::cin >> chinese >> math >> english;
        Student student(i, chinese, math, english);
        students[i] = student;
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
    for (int i = 1; i <= N; i++) {
        std::cout << get_rank(i, N) << std::endl;
    }
    return 0;
}