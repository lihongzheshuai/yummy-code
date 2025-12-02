#include <iostream>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left, *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// 1. 前序遍历：根 -> 左 -> 右
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";  // 访问根
    preOrder(root->left);      // 递归左
    preOrder(root->right);     // 递归右
}

// 2. 中序遍历：左 -> 根 -> 右
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);       // 递归左
    cout << root->val << " ";  // 访问根
    inOrder(root->right);      // 递归右
}

// 3. 后序遍历：左 -> 右 -> 根
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);     // 递归左
    postOrder(root->right);    // 递归右
    cout << root->val << " ";  // 访问根
}

int main() {
    /* 构建如下二叉树
         A
       /   \
      B     C
       \   /
        D E
    */
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->right = new TreeNode('D');
    root->right->left = new TreeNode('E');

    cout << "前序遍历: ";
    preOrder(root);
    cout << endl;
    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;
    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;

    return 0;
}