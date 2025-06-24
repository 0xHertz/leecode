/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
*/


// Definition for a binary tree node.
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
    public:
    // 中序
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        inorder(root,res);
        return res;
    }
    void inorder(TreeNode * ptr,vector<int>& res){
        if (!ptr) {
            return;
        }else{
            inorder(ptr->left,res);
            res.push_back(ptr->val);
            inorder(ptr->right,res);
        }
    }
};

int main() {
    Solution solution;

    // 测试用例 1：空树
    TreeNode* root = nullptr;
    vector<int> result = solution.inorderTraversal(root);
    cout << "Test Case 1: ";
    for (int val : result) cout << val << " ";
    cout << (result.empty() ? "Passed" : "Failed") << endl;

    // 测试用例 2：单节点树
    root = new TreeNode(1);
    result = solution.inorderTraversal(root);
    cout << "Test Case 2: ";
    for (int val : result) cout << val << " ";
    cout << (result == vector<int>{1} ? "Passed" : "Failed") << endl;

    // 测试用例 3：完全二叉树
    root = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    result = solution.inorderTraversal(root);
    cout << "Test Case 3: ";
    for (int val : result) cout << val << " ";
    cout << (result == vector<int>{2, 1, 3} ? "Passed" : "Failed") << endl;

    // 测试用例 4：不完全二叉树
    root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    result = solution.inorderTraversal(root);
    cout << "Test Case 4: ";
    for (int val : result) cout << val << " ";
    cout << (result == vector<int>{4, 2, 1, 3} ? "Passed" : "Failed") << endl;

    // 测试用例 5：只有左子树
    root = new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
    result = solution.inorderTraversal(root);
    cout << "Test Case 5: ";
    for (int val : result) cout << val << " ";
    cout << (result == vector<int>{3, 2, 1} ? "Passed" : "Failed") << endl;

    // 测试用例 6：只有右子树
    root = new TreeNode(1, nullptr, new TreeNode(2, nullptr, new TreeNode(3)));
    result = solution.inorderTraversal(root);
    cout << "Test Case 6: ";
    for (int val : result) cout << val << " ";
    cout << (result == vector<int>{1, 2, 3} ? "Passed" : "Failed") << endl;

    return 0;
}
