#include <iostream>
using namespace std;

const int MAX_SIZE = 5;  // 实际只能存 4 个，留 1 个位区分空/满
int q[MAX_SIZE];
int head = 0, tail = 0;

// 入队
bool enqueue(int val) {
    if ((tail + 1) % MAX_SIZE == head) {
        cout << "队列满，无法插入: " << val << endl;
        return false;
    }
    q[tail] = val;
    tail = (tail + 1) % MAX_SIZE;
    return true;
}

// 出队
bool dequeue() {
    if (head == tail) {
        cout << "队列空，无法删除" << endl;
        return false;
    }
    cout << "出队: " << q[head] << endl;
    head = (head + 1) % MAX_SIZE;
    return true;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);  // 队列容量为5，存满4个即判满，这里会失败

    dequeue();   // 出队 1
    enqueue(5);  // 现在有位置了，可以入队 5

    return 0;
}