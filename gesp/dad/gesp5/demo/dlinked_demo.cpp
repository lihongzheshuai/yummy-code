#include <iostream>
#include <vector>
using namespace std;

// 双向链表节点定义
struct DNode {
    int data;     // 数据域
    DNode* prev;  // 指向前一个节点
    DNode* next;  // 指向下一个节点
    // 构造函数
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// 创建双向链表
// @param vals: 用于创建链表的数据数组
// @return: 返回创建的双向链表头指针
DNode* createDList(const vector<int>& vals) {
    DNode* head = nullptr;  // 头指针，指向链表的第一个节点
    DNode* tail = nullptr;  // 尾指针，指向链表的最后一个节点

    // 遍历输入数组，依次创建节点
    for (int val : vals) {
        DNode* newNode = new DNode(val);  // 创建新节点
        if (!head) {
            // 如果是第一个节点，同时更新头尾指针
            head = tail = newNode;
        } else {
            // 否则在尾部追加新节点
            tail->next = newNode;  // 当前尾节点的next指向新节点
            newNode->prev = tail;  // 新节点的prev指向旧尾节点
            tail = newNode;        // 更新尾指针为新节点
        }
    }
    // 返回链表头指针
    return head;
}

// 正向遍历双向链表，打印所有节点的值
// @param head: 双向链表的头指针
void traverseForward(DNode* head) {
    // 遍历双向链表
    for (DNode* cur = head; cur; cur = cur->next) cout << cur->data << " ";
    cout << endl;  // 最后换行
}

// 反向遍历双向链表
void traverseBackward(DNode* tail) {
    // 从尾节点开始遍历
    // cur不为空时继续遍历,每次移动到前一个节点
    for (DNode* cur = tail; cur; cur = cur->prev)
        // 输出当前节点的数据
        cout << cur->data << " ";
    // 换行
    cout << endl;
}

// 在位置pos插入节点（pos从0开始）
// @param head: 双向链表头指针的引用，便于修改头指针
// @param pos: 要插入的位置（0表示头部）
// @param val: 要插入的新节点的值
void insertAtPosition(DNode*& head, int pos, int val) {
    DNode* newNode = new DNode(val);  // 创建新节点

    // 如果插入到头部
    if (pos == 0) {
        newNode->next = head;  // 新节点的next指向原头节点
        if (head) {
            head->prev = newNode;  // 如果原头节点存在，prev指向新节点
        }
        head = newNode;  // 更新头指针为新节点
        return;
    }

    DNode* cur = head;  // 从头节点开始遍历
    // 遍历到插入位置的前一个节点
    for (int i = 0; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    // 如果找到了插入位置的前一个节点
    if (cur) {
        newNode->next = cur->next;      // 新节点的next指向当前位置的下一个节点
        newNode->prev = cur;            // 新节点的prev指向当前位置节点
        if (cur->next)                  // 如果当前位置的下一个节点存在
            cur->next->prev = newNode;  // 下一个节点的prev指向新节点
        cur->next = newNode;            // 当前节点的next指向新节点
    }
}

// 在指定节点后插入新节点
// @param target: 目标节点指针，在其后插入新节点
// @param val: 要插入的新节点的值
void insertAfter(DNode* target, int val) {
    if (!target) {
        return;  // 如果目标节点为空，直接返回
    }

    DNode* newNode = new DNode(val);  // 创建新节点

    // 新节点的next指向目标节点的下一个节点
    newNode->next = target->next;
    // 新节点的prev指向目标节点
    newNode->prev = target;

    // 如果目标节点的下一个节点存在，让其prev指向新节点
    if (target->next) target->next->prev = newNode;

    // 目标节点的next指向新节点
    target->next = newNode;
}

// 删除指定位置的节点
// @param head: 双向链表的头指针的引用
// @param pos: 要删除的节点的位置（从0开始）
void deleteAtPosition(DNode*& head, int pos) {
    if (!head) {
        // 如果链表为空，直接返回
        return;
    }

    DNode* cur = head;  // 用于遍历的指针

    // 如果要删除的是头节点
    if (pos == 0) {
        head = head->next;  // 头指针指向下一个节点
        if (head) {
            head->prev = nullptr;  // 新头节点的prev设为nullptr
        }
        delete cur;  // 释放原头节点
        return;
    }

    // 遍历到要删除的节点
    for (int i = 0; i < pos && cur; ++i) {
        cur = cur->next;
    }

    // 如果找到了要删除的节点
    if (cur) {
        if (cur->prev) {
            cur->prev->next =
                cur->next;  // 前一个节点的next指向当前节点的下一个节点
        }
        if (cur->next) {
            cur->next->prev =
                cur->prev;  // 下一个节点的prev指向当前节点的前一个节点
        }
        delete cur;  // 释放当前节点
    }
}

// 删除链表中第一个值为val的节点
// @param head: 双向链表头指针的引用，便于修改头指针
// @param val: 要删除的节点的值（只删除第一个匹配的节点）
void deleteNode(DNode*& head, int val) {
    DNode* cur = head;  // 用于遍历链表的指针

    // 遍历链表，查找第一个值为val的节点
    while (cur && cur->data != val) {
        cur = cur->next;
    }

    // 如果找到了该节点
    if (cur) {
        // 如果要删除的不是头节点
        if (cur->prev) {
            // 前一个节点的next指向当前节点的下一个节点
            cur->prev->next = cur->next;
        } else {
            // 如果要删除的是头节点，更新头指针
            head = cur->next;
        }

        // 如果当前节点不是尾节点
        if (cur->next) {
            // 下一个节点的prev指向当前节点的前一个节点
            cur->next->prev = cur->prev;
        }

        // 释放当前节点的内存
        delete cur;
    }
}

// 反转双向链表
// @param head: 双向链表的头指针
// @return: 反转后的链表头指针
DNode* reverseDList(DNode* head) {
    DNode* cur = head;     // 当前遍历到的节点
    DNode* tmp = nullptr;  // 用于临时保存前驱指针

    // 遍历链表，交换每个节点的prev和next指针
    while (cur) {
        // 先保存当前节点的prev指针（原链表的前驱）
        tmp = cur->prev;
        // 交换当前节点的prev和next指针
        cur->prev = cur->next;
        cur->next = tmp;
        // 移动到下一个节点（由于prev和next已交换，所以用cur->prev）
        cur = cur->prev;
    }

    // 反转过程中，每个节点的prev和next都被交换。
    // 循环结束时，cur为nullptr，tmp为尾节点的前一个节点（原倒数第二个节点）
    // 由于交换了prev和next，tmp->prev实际上指向原链表的最后一个节点（即新链表的头节点5）。
    // 所以需要将head赋值为tmp->prev，才能得到反转后的新头节点。
    if (tmp) {
        head = tmp->prev;
    }
    return head;
}

// 示例用法
int main() {
    // 创建一个包含1~5的整数的vector
    vector<int> vals = {1, 2, 3, 4, 5};
    // 用vector创建双向链表
    DNode* head = createDList(vals);
    // 正向遍历链表并输出
    traverseForward(head);
    // 反向遍历链表并输出（从最后一个节点开始）
    traverseBackward(head->next->next->next->next);

    // 在第2个位置插入值为6的节点
    insertAtPosition(head, 2, 6);
    // 正向遍历链表并输出
    traverseForward(head);

    // 在头部插入值为0的节点
    insertAtPosition(head, 0, 0);
    // 正向遍历链表并输出
    traverseForward(head);

    // 在第3个节点（值为3）后插入值为7的节点
    insertAfter(head->next->next, 7);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除头节点
    deleteAtPosition(head, 0);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除中间节点（原第3个节点，现为第2个节点，值为3）
    deleteAtPosition(head, 2);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除值为7的节点
    deleteNode(head, 7);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除值为6的节点
    deleteNode(head, 6);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除值为1的节点
    deleteNode(head, 1);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除值为0的节点
    deleteNode(head, 0);
    // 正向遍历链表并输出
    traverseForward(head);

    // 删除值为5的节点
    deleteNode(head, 5);
    // 正向遍历链表并输出
    traverseForward(head);

    // 在头部插入值为1的节点
    insertAtPosition(head, 0, 1);
    // 正向遍历链表并输出
    traverseForward(head);

    // 在第4个位置插入值为5的节点
    insertAtPosition(head, 4, 5);
    // 正向遍历链表并输出
    traverseForward(head);

    // 反转链表
    head = reverseDList(head);
    // 正向遍历链表并输出
    traverseForward(head);

    // 程序结束
    return 0;
}
