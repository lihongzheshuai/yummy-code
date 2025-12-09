#include <iostream>
#include <stack>  // 引入头文件
using namespace std;

int main() {
    stack<int> s;  // 定义一个存储 int 的栈

    // 1. 入栈 push
    s.push(10);
    s.push(20);
    s.push(30);
    // 此时栈内结构（从底到顶）：10 -> 20 -> 30

    // 2. 取栈顶 top
    cout << "栈顶元素: " << s.top() << endl;  // 输出 30

    // 3. 出栈 pop
    s.pop();                                              // 移除 30
    cout << "弹出一个后，栈顶元素: " << s.top() << endl;  // 输出 20

    // 4. 判空 empty 和 大小 size
    if (!s.empty()) {
        cout << "栈不为空，大小为: " << s.size() << endl;  // 输出 2
    }

    return 0;
}