#include <iostream>
#include <vector>
using namespace std;

// 定义链表节点结构体
struct Node {
    int data;    // 节点存储的数据
    Node* next;  // 指向下一个节点的指针
    // 构造函数，初始化节点
    // @param val: 节点的初始值
    Node(int val)
        : data(val), next(nullptr) {}  // 初始化列表，next指针初始化为空
};

// 创建链表函数，使用尾插法
// @param vals: 用于创建链表的数据数组
// @return: 返回创建的链表头指针
Node* createList(const vector<int>& vals) {
    // 初始化头尾指针为空
    Node* head = nullptr;  // 头指针，指向链表的第一个节点
    Node* tail = nullptr;  // 尾指针，指向链表的最后一个节点

    // 遍历输入数组，依次创建节点
    for (int val : vals) {
        // 创建新节点
        Node* newNode = new Node(val);

        // 如果是第一个节点，同时更新头尾指针
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        // 否则在尾部追加新节点
        else {
            tail->next = newNode;  // 当前尾节点指向新节点
            tail = newNode;        // 更新尾节点指针
        }
    }

    // 返回链表头指针
    return head;
}

// 在链表指定位置插入节点的函数，位置从0开始
// @param head: 链表头指针的引用，用于修改链表头指针
// @param pos: 插入位置（插入到pos位置，原pos位置的节点后移）
// @param val: 要插入的节点值
void insertAtPosition(Node*& head, int pos, int val) {
    // 从头节点开始遍历
    Node* cur = head;

    // 如果pos为0，插入头节点
    if (pos == 0) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }

    // 遍历到指定位置，同时确保不会访问空指针
    for (int i = 0; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    // 如果找到了指定位置（cur不为空）
    if (cur) {
        // 创建新节点
        Node* newNode = new Node(val);
        // 新节点的next指向当前节点的下一个节点
        newNode->next = cur->next;
        // 当前节点的next指向新节点
        cur->next = newNode;
    }
}

// 在给定节点后插入节点的函数
// @param target: 给定节点指针
// @param val: 要插入的节点值
void insertAfter(Node* target, int val) {
    // 如果给定节点为空，直接返回空指针
    if (!target) {
        return;
    }

    // 创建新节点
    Node* newNode = new Node(val);
    // 新节点的next指向给定节点的下一个节点
    newNode->next = target->next;
    // 给定节点的next指向新节点
    target->next = newNode;
}

// 删除链表中值为val的节点的函数
// @param head: 链表头指针的引用，用于修改链表头指针
// @param val: 要删除的节点的值
void deleteNode(Node*& head, int val) {
    // 如果链表为空，直接返回空指针
    if (!head) {
        return;
    }

    // 如果头节点就是要删除的节点
    if (head->data == val) {
        Node* tmp = head;   // 保存头节点指针
        head = head->next;  // 头指针指向下一个节点
        delete tmp;         // 释放原头节点内存
        return;             
    }

    // 遍历链表寻找值为val的节点
    Node* cur = head;
    // 当后继节点存在且值不等于val时继续遍历
    while (cur->next && cur->next->data != val) {
        cur = cur->next;
    }

    // 如果找到了值为val的节点（cur->next不为空）
    if (cur->next) {
        Node* tmp = cur->next;  // 保存要删除的节点指针
        cur->next = tmp->next;  // 跳过要删除的节点
        delete tmp;             // 释放要删除节点的内存
    }

    return;
}

// 删除链表中位置pos的节点的函数
// @param head: 链表头指针的引用，用于修改链表头指针
// @param pos: 删除节点的位置（从0开始）
void deleteAtPosition(Node*& head, int pos) {
    // 如果链表为空，直接返回空指针
    if (!head) {
        return;
    }

    // 如果pos为0，删除头节点
    if (pos == 0) {
        Node* tmp = head;   // 保存头节点指针
        head = head->next;  // 头指针指向下一个节点
        delete tmp;         // 释放原头节点内存
        return;             // 返回新的头指针
    }

    // 遍历链表寻找要删除的节点
    Node* cur = head;
    // 遍历到要删除的节点的前一个节点
    for (int i = 0; i < pos - 1 && cur->next; ++i) {
        cur = cur->next;
    }

    // 如果找到了要删除的节点（cur->next不为空）
    if (cur->next) {
        Node* tmp = cur->next;  // 保存要删除的节点指针
        cur->next = tmp->next;  // 跳过要删除的节点
        delete tmp;             // 释放要删除节点的内存
    }

    return;
}

// 遍历链表并打印所有节点的值
// @param head: 链表头指针
void traverse(Node* head) {
    // 从头节点开始遍历，直到遇到空指针
    for (Node* cur = head; cur; cur = cur->next)
        // 打印当前节点的值，并用空格分隔
        cout << cur->data << " ";
    // 遍历结束后换行
    cout << endl;
}

// 反转链表函数，将链表反向连接
// @param head: 链表头指针
// @return: 返回反转后的链表头指针
Node* reverseList(Node* head) {
    // prev指向前一个节点，初始为空
    Node* prev = nullptr;
    // cur指向当前节点，初始为头节点
    Node* cur = head;

    // 遍历链表直到当前节点为空
    while (cur) {
        // 保存下一个节点，因为马上要改变cur->next
        Node* next = cur->next;
        // 反转指针，让当前节点指向前一个节点
        cur->next = prev;
        // prev移动到当前节点
        prev = cur;
        // cur移动到下一个节点
        cur = next;
    }

    return prev;  // 新头结点
}

int main() {
    // 测试用例1: 创建链表
    vector<int> vals1 = {1, 2, 3, 4, 5};
    Node* head1 = createList(vals1);
    traverse(head1);

    // 测试用例2: 在位置0插入值为6的节点
    insertAtPosition(head1, 0, 6);
    traverse(head1);

    // 测试用例3: 在位置2插入值为7的节点
    insertAtPosition(head1, 2, 7);
    traverse(head1);

    // 测试用例4: 在位置2的节点后插入值为7的节点
    Node* target = head1->next->next;
    insertAfter(target, 8);
    traverse(head1);

    // 测试用例5: 删除位置0的节点
    deleteAtPosition(head1, 0);
    traverse(head1);

    // 测试用例6: 删除位置2的节点
    deleteAtPosition(head1, 2);
    traverse(head1);

    // 测试用例7: 删除值为7的节点
    deleteNode(head1, 7);
    traverse(head1);

    // 测试用例8: 反转链表
    Node* head3 = reverseList(head1);
    traverse(head3);

    return 0;
}
