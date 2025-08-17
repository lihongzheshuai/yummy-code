#include <iostream>
#include <vector>
using namespace std;

// 单向循环链表节点
// 循环链表节点结构体定义
struct CNode {
    int data;     // 节点数据
    CNode* next;  // 指向下一个节点的指针
    // 构造函数，初始化节点数据和指针
    CNode(int val) : data(val), next(nullptr) {}
};

/**
 * 创建单向循环链表
 * @param vals 用于创建链表的数据数组
 * @return 返回创建的循环链表的头节点
 */
CNode* createCList(const vector<int>& vals) {
    // 初始化头尾指针为空
    CNode* head = nullptr;
    CNode* tail = nullptr;

    // 遍历输入数组，逐个创建节点
    for (int val : vals) {
        // 创建新节点
        CNode* newNode = new CNode(val);

        if (!head) {
            // 如果是第一个节点，头尾指针都指向它
            head = tail = newNode;
            tail->next = head;  // 首尾相连，形成循环
        } else {
            // 非第一个节点，将新节点接到尾部
            tail->next = newNode;
            tail = newNode;
            tail->next = head;  // 更新尾节点指向头节点，保持循环特性
        }
    }
    return head;
}

/**
 * 在循环链表指定位置插入新节点
 * @param head 循环链表的头节点引用
 * @param pos 要插入的位置，从0开始
 * @param val 要插入的值
 */
void insertAtPosition(CNode*& head, int pos, int val) {
    // 创建新节点
    CNode* newNode = new CNode(val);

    if (!head) {            // 空链表情况处理
        head = newNode;     // 新节点作为头节点
        head->next = head;  // 指向自身形成循环
        return;
    }

    if (pos == 0) {  // 在头部插入的情况
        CNode* tail = head;
        // 找到尾节点
        while (tail->next != head) {
            tail = tail->next;
        }
        // 新节点指向原头节点
        newNode->next = head;
        // 尾节点指向新节点
        tail->next = newNode;
        // 更新头节点
        head = newNode;
        return;
    }

    // 找到插入位置的前一个节点
    CNode* cur = head;
    for (int i = 0; i < pos - 1 && cur->next != head; ++i) {
        cur = cur->next;
    }

    // 执行插入操作
    newNode->next = cur->next;  // 新节点指向下一个节点
    cur->next = newNode;        // 当前节点指向新节点
}

/**
 * 在给定节点后插入新节点
 * @param target 给定节点指针
 * @param val 要插入的值
 */
void insertAfter(CNode* target, int val) {
    // 如果给定节点为空，直接返回空指针
    if (!target) {
        return;
    }

    // 创建新节点
    CNode* newNode = new CNode(val);
    // 新节点的next指向给定节点的下一个节点
    newNode->next = target->next;
    // 给定节点的next指向新节点
    target->next = newNode;
}

/**
 * 遍历循环链表
 * @param head 循环链表的头节点
 */
void traverseCList(CNode* head) {
    // 空链表直接返回
    if (!head) {
        return;
    }

    // 从头节点开始遍历
    CNode* cur = head;

    // 使用do-while循环遍历,因为至少要访问一次头节点
    do {
        // 输出当前节点数据
        cout << cur->data << " ";
        // 移动到下一个节点
        cur = cur->next;
    } while (cur != head);  // 当再次回到头节点时停止

    // 换行
    cout << endl;
}

/**
 * 删除循环链表中给定位置的节点
 * @param head 循环链表的头节点的引用，用于修改头节点
 * @param pos 要删除的节点的位置（从0开始）
 */
void deleteAtPosition(CNode*& head, int pos) {
    // 如果链表为空，直接返回
    if (!head) {
        return;
    }

    // 如果要删除的是头节点
    if (pos == 0) {
        // 如果链表只有一个节点，直接释放头节点
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        // 找到尾节点
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;

        // 保存头节点指针
        CNode* tmp = head;
        // 头节点指向下一个节点
        head = head->next;
        // 尾节点的next指向新头节点
        tail->next = head;
        // 释放原头节点
        delete tmp;
        return;
    }

    // 找到要删除的节点的前一个节点
    CNode* cur = head;
    for (int i = 0; i < pos - 1 && cur->next != head; ++i) cur = cur->next;

    // 如果找到了要删除的节点（cur->next不为空）
    if (cur->next) {
        // 保存要删除的节点指针
        CNode* tmp = cur->next;
        // 当前节点指向下一个节点
        cur->next = tmp->next;
        // 释放要删除节点
        delete tmp;
    }
}

/**
 * 删除循环链表中给定值的所有节点
 * @param head 循环链表的头节点的引用，用于修改头节点
 * @param val 要删除的节点的值
 */
void deleteNode(CNode*& head, int val) {
    // 如果链表为空，直接返回
    if (!head) {
        return;
    }

    // 用于遍历链表的指针
    CNode* cur = head;
    // 用于保存前一个节点的指针
    CNode* prev = nullptr;

    do {
        // 如果当前节点的值等于给定值
        if (cur->data == val) {
            // 如果当前节点是头节点
            if (cur == head) {
                // 找到尾节点
                CNode* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                // 更新头节点为下一个节点
                head = cur->next;
                // 更新尾节点的next指向新头节点
                tail->next = head;
                // 释放原头节点
                delete cur;
                // 移动到下一个节点
                cur = head;
            } else {
                // 将前一个节点的next指向当前节点的下一个节点
                prev->next = cur->next;
                // 释放当前节点
                delete cur;
                // 移动到下一个节点
                cur = prev->next;
            }
        } else {
            // 移动前一个节点指针
            prev = cur;
            // 移动到下一个节点
            cur = cur->next;
        }
    } while (cur != head);
}

/**
 * 反转循环链表
 * @param head 循环链表的头节点
 * @return 返回反转后的循环链表头节点
 */
CNode* reverseCList(CNode* head) {
    // 特殊情况：空链表或只有一个节点
    if (!head || head->next == head) {
        return head;
    }

    CNode* prev = nullptr;  // 保存前一个节点指针
    CNode* cur = head;      // 当前节点指针
    CNode* tail = head;     // 尾节点指针

    // 找到尾节点
    while (tail->next != head) {
        tail = tail->next;
    }

    do {
        // 保存下一个节点指针
        CNode* nextNode = cur->next;
        // 当前节点指向前一个节点或新尾节点
        cur->next = prev ? prev : tail;
        // 更新前一个节点指针
        prev = cur;
        // 更新当前节点指针
        cur = nextNode;
    } while (cur != head);  // 直到回到头节点

    // 更新头节点
    head = prev;
    // 返回反转后的头节点
    return head;
}

int main() {
    // 创建一个循环链表，初始值为1，2，3，4，5
    vector<int> vals = {1, 2, 3, 4, 5};
    CNode* head = createCList(vals);
    
    // 遍历循环链表
    traverseCList(head);

    // 在位置0处插入节点0
    insertAtPosition(head, 0, 0);
    // 遍历循环链表
    traverseCList(head);

    // 在位置2处插入节点6
    insertAtPosition(head, 2, 6);
    // 遍历循环链表
    traverseCList(head);

    // 在位置7处插入节点7
    insertAtPosition(head, 7, 7);
    // 遍历循环链表
    traverseCList(head);

    // 在节点2的后面插入节点8
    insertAfter(head->next->next, 8);
    // 遍历循环链表
    traverseCList(head);

    // 删除位置0处的节点
    deleteAtPosition(head, 0);
    // 遍历循环链表
    traverseCList(head);

    // 删除位置7处的节点
    deleteAtPosition(head, 7);
    // 遍历循环链表
    traverseCList(head);

    // 删除值为1的节点
    deleteNode(head, 1);
    // 遍历循环链表
    traverseCList(head);

    // 删除值为6的节点
    deleteNode(head, 6);
    // 遍历循环链表
    traverseCList(head);

    // 删除值为8的节点
    deleteNode(head, 8);
    // 遍历循环链表
    traverseCList(head);

    // 在位置0处插入节点1
    insertAtPosition(head, 0, 1);
    // 遍历循环链表
    traverseCList(head);

    // 反转循环链表
    head = reverseCList(head);
    // 遍历循环链表
    traverseCList(head);
}