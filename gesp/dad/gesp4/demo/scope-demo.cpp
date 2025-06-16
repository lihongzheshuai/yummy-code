#include <iostream>
using namespace std;

int count = 0;  // 全局变量

void addOne() {
    int count = 0;
    ::count = count + 1;  // 修改全局变量
}

int main() {
    addOne();
    cout << "count的值是：" << count << endl;
    return 0;
}