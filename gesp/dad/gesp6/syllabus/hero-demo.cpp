#include <iostream>
#include <string>
using namespace std;
class Hero {
   public:
    string name;

    // 构造函数
    Hero(string n) {
        name = n;
        cout << name << " 英雄降临！(构造函数被调用)" << endl;
    }

    // 析构函数
    ~Hero() { cout << name << " 英雄牺牲了... (析构函数被调用)" << endl; }
};

int main() {
    {
        Hero h1("盖伦");  // 创建对象，输出：盖伦 英雄降临！
    }  // 出了这个大括号，h1 作用域结束，对象销毁, // 输出：盖伦 英雄牺牲了...
    cout << "----" << endl;

    return 0;
}