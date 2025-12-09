#include <iostream>
#include <string>
using namespace std;

// 1. 定义一个类：Student (学生)
class Student {
   public:  // 访问权限：公开的
    // --- 属性 (成员变量) ---
    string name;
    int age;
    int score;

    // --- 行为 (成员函数) ---
    void introduce();  // 声明：方法原型，实现在类外部

    void study() {
        score++;
        cout << name << "正在努力学习，分数+1，现在分数是：" << score << endl;
    }
};

// 在类外部使用作用域解析符 :: 实现 introduce 方法
void Student::introduce() {
    cout << "大家好，我是" << name << "，今年" << age << "岁。" << endl;
}

int main() {
    // 2. 创建对象 (实例化)
    Student stu1;  // 创建了一个叫 stu1 的对象

    // 3. 使用对象 (访问属性和方法)
    stu1.name = "小明";
    stu1.age = 13;
    stu1.score = 90;

    stu1.introduce();  // 调用方法
    stu1.study();      // 调用方法

    // 创建另一个对象
    Student stu2;
    stu2.name = "小红";
    stu2.introduce();  // 小红和小明互不干扰

    return 0;
}