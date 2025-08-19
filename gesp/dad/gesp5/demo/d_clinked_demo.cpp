#include <iostream>
#include <vector>

struct Node {
    // 节点数据域
    int data;
    // 指向前驱节点的指针
    Node* prev;
    // 指向后继节点的指针
    Node* next;
    // 构造函数，初始化节点
    // @param val: 节点数据值
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

/**
 * 创建一个双向循环链表（Doubly Circular Linked List）
 * @param arr 输入的整型数组，用于初始化链表节点的数据域
 * @return 返回链表头指针，若数组为空则返回nullptr
 */
Node* createDCLL(std::vector<int> arr) {
    // 如果输入数组为空，直接返回空指针
    if (arr.empty()) {
        return nullptr;
    }

    // 创建头节点，并初始化尾指针
    Node* head = new Node(arr[0]);
    Node* tail = head;

    // 依次创建后续节点，并连接前后指针
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);  // 新节点
        tail->next = newNode;  // 当前尾节点的next指向新节点
        newNode->prev = tail;  // 新节点的prev指向当前尾节点
        tail = newNode;        // 更新尾节点为新节点
    }

    // 将链表首尾相连，形成循环
    head->prev = tail;
    tail->next = head;

    // 返回头指针
    return head;
}

/**
 * 在双向循环链表指定位置插入新节点
 * @param head 双向循环链表的头指针的引用，用于修改头指针
 * @param pos 要插入的位置（从0开始）
 * @param val 要插入的节点的数据域值
 */
void insertAtPosition(Node*& head, int pos, int val) {
    // 创建新节点
    Node* newNode = new Node(val);

    if (pos == 0) {
        // 如果要插入的是头节点
        newNode->next = head;        // 新节点的next指向原头节点
        newNode->prev = head->prev;  // 新节点的prev指向原头节点的prev
        head->prev->next = newNode;  // 原头节点的prev的next指向新节点
        head->prev = newNode;        // 更新头节点的prev为新节点
        head = newNode;              // 更新头指针为新节点
        return;
    }

    Node* cur = head;  // 从头节点开始遍历
    for (int i = 0; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    // 如果找到了要插入的位置（cur不为空）
    if (cur) {
        newNode->next = cur->next;  // 新节点的next指向当前位置的下一个节点
        newNode->prev = cur;  // 新节点的prev指向当前位置节点
        if (cur->next) {      // 如果当前位置的下一个节点存在
            cur->next->prev = newNode;  // 下一个节点的prev指向新节点
        }
        cur->next = newNode;  // 当前节点的next指向新节点
    }
}

/**
 * 在指定节点后插入新节点
 * @param head 双向循环链表的头指针的引用，用于修改头指针
 * @param pos 要插入的节点指针，在其后插入新节点
 * @param val 要插入的节点的数据域值
 */
void insertAfter(Node*& head, Node* pos, int val) {
    // 如果指定节点为空，直接返回
    if (!pos) {
        return;
    }

    // 创建新节点
    Node* newNode = new Node(val);

    // 新节点的next指向指定节点的next
    newNode->next = pos->next;

    // 新节点的prev指向指定节点
    newNode->prev = pos;

    // 指定节点的next的prev指向新节点
    pos->next->prev = newNode;

    // 指定节点的next指向新节点
    pos->next = newNode;
}

/**
 * 删除双向循环链表指定位置的节点
 * @param head 双向循环链表的头指针的引用，用于修改头指针
 * @param pos 要删除的位置（从0开始）
 */
void deleteAtPosition(Node*& head, int pos) {
    // 如果链表为空，直接返回
    if (!head) {
        return;
    }

    // 如果要删除的是头节点
    if (pos == 0) {
        // 找到尾节点
        Node* tail = head->prev;
        // 尾节点的next指向头节点的下一个节点
        tail->next = head->next;
        // 释放头节点
        delete head;
        // 更新头指针为下一个节点
        head = tail->next;
        // 更新头节点的prev为新头节点的prev（即原尾节点）
        head->prev = tail;
        return;
    }

    // 遍历到指定位置
    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur; ++i) {
        cur = cur->next;
    }

    // 如果找到了要删除的位置（cur不为空）
    if (cur) {
        // 保存要删除节点的指针
        Node* toDelete = cur->next;
        // 当前节点指向下下一个节点
        cur->next = toDelete->next;
        // 释放要删除节点的内存
        delete toDelete;
        // 更新当前节点的prev指向要删除节点的prev
        cur->next->prev = cur;
        return;
    }
}

/**
 * 删除双向循环链表中指定值的所有节点
 * @param head 双向循环链表的头指针的引用，用于修改头指针
 * @param val 要删除的节点的值
 */
void deleteNode(Node*& head, int val) {
    // 如果链表为空，直接返回
    if (!head) {
        return;
    }

    // 用于遍历链表的指针
    Node* cur = head;
    // 用于保存前一个节点的指针
    Node* prev = nullptr;

    do {
        // 如果当前节点的值等于给定值
        if (cur->data == val) {
            // 如果当前节点是头节点
            if (cur == head) {
                // 找到尾节点
                Node* tail = head->prev;
                // 更新头节点为下一个节点
                head = cur->next;
                // 更新尾节点的next指向新头节点
                tail->next = head;
                // 释放原头节点
                delete cur;
                // 更新头节点的prev为原尾节点
                head->prev = tail;
                cur = head;
            } else {
                // 将前一个节点的next指向当前节点的下一个节点
                prev->next = cur->next;
                // 释放当前节点
                delete cur;
                // 更新前一个节点的next的prev为前一个节点
                prev->next->prev = prev;
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
 * 正向遍历双向循环链表
 * @param head 双向循环链表头指针
 */
void traverseForward(Node* head) {
    // 从头节点开始遍历，直到回到头节点
    Node* cur = head;
    do {
        // 输出当前节点的数据
        std::cout << cur->data << " ";
        // 移动到下一个节点
        cur = cur->next;
    } while (cur != head);
    // 换行
    std::cout << std::endl;
}

void printBackward(Node* head) {
    if (!head) return;
    Node* p = head->prev;  // 从尾开始
    Node* tail = p;
    do {
        std::cout << p->data << " ";
        p = p->prev;
    } while (p != tail);
    std::cout << std::endl;
}

void reverse(Node*& head) {
    // 如果链表为空或只有一个节点，直接返回
    if (!head || head->next == head) {
        return;
    }

    // 用于遍历链表的指针
    Node* cur = head;
    // 用于保存前一个节点的指针
    Node* prev = head->prev;

    do {
        // 保存当前节点的下一个节点
        Node* next = cur->next;
        // 反转当前节点的指针
        cur->next = prev;
        cur->prev = next;
        // 移动前一个节点指针
        prev = cur;
        // 移动到下一个节点
        cur = next;
    } while (cur != head);

    // 更新头指针
    head = prev;
}

int main() {
    // 创建一个包含1~5的整数的双向循环链表
    std::vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createDCLL(arr);

    // 正向遍历链表并输出
    traverseForward(head);

    // 在头部插入一个值为0的节点
    insertAtPosition(head, 0, 0);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 在第二个位置插入一个值为6的节点
    insertAtPosition(head, 2, 6);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 在最后一个位置插入一个值为7的节点
    insertAtPosition(head, 7, 7);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 在第二个节点（值为2）后插入一个值为8的节点
    insertAfter(head, head->next, 8);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 删除头节点
    deleteAtPosition(head, 0);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 删除第三个节点（原值为3）
    deleteAtPosition(head, 2);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 删除头节点
    deleteAtPosition(head, 0);
    // 再次正向遍历链表并输出
    traverseForward(head);

    // 反向遍历链表并输出（从最后一个节点开始）
    printBackward(head);

    // 删除值为8的节点
    deleteNode(head, 8);
    // 再次反向遍历链表并输出
    printBackward(head);

    // 删除值为7的节点
    deleteNode(head, 7);
    // 再次反向遍历链表并输出
    printBackward(head);

    // 删除值为4的节点
    deleteNode(head, 4);
    // 再次反向遍历链表并输出
    printBackward(head);

    // 插入一个值为4的节点在第二个位置
    // 插入一个值为1的节点在头部
    insertAtPosition(head, 2, 4);
    insertAtPosition(head, 0, 1);

    // 反转链表
    reverse(head);

    // 再次正向遍历链表并输出
    traverseForward(head);

    // 再次反向遍历链表并输出（从最后一个节点开始）
    printBackward(head);

    return 0;
}