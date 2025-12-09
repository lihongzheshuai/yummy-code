#include <iostream>
#include <queue>  // 引入头文件
using namespace std;

int main() {
    queue<string> q;  // 定义一个存储 string 的队列

    // 1. 入队 push
    q.push("张三");
    q.push("李四");
    q.push("王五");
    // 此时队列结构（从头到尾）：张三 -> 李四 -> 王五

    // 2. 访问队头 front 和 队尾 back
    cout << "现在轮到谁打饭: " << q.front() << endl;  // 张三
    cout << "队尾排的是谁: " << q.back() << endl;     // 王五

    // 3. 出队 pop
    q.pop();                                      // 张三打完饭走了
    cout << "下一个轮到: " << q.front() << endl;  // 李四

    return 0;
}