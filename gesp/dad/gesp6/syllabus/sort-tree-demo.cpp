#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 插入节点
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else if (val > root->val)
        root->right = insertBST(root->right, val);
    return root;
}

// 查找节点
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == NULL || root->val == val) return root;
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// 中序遍历验证
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    TreeNode* root = NULL;
    int nums[] = {50, 30, 70, 20, 40, 60, 80};
    for (int x : nums) root = insertBST(root, x);
    cout << root->val << endl;
    cout << "BST 中序遍历: ";
    inOrder(root);  // 输出: 20 30 40 50 60 70 80
    cout << endl;

    TreeNode* found = searchBST(root, 40);
    if (found)
        cout << "Found: " << found->val << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}