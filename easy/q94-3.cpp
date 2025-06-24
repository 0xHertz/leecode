/*
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
*/


// Definition for a binary tree node.
#include <stack>
#include <vector>
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
    // 中序，循环版
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res = {};
        stack<TreeNode*> stackn;
        if (!root) {
            return res;
        }
        TreeNode* cur = root;
        while (cur != nullptr || !stackn.empty()) {
            while (cur != nullptr) {
                stackn.push(cur);
                cur = cur->left;
            }
            cur = stackn.top();
            stackn.pop();
            res.push_back(cur->val); // 访问
            cur = cur->right;
        }
        return res;
    }
    // 先序，循环版
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res = {};
        stack<TreeNode*> stackn;
        if (!root) {
            return res;
        }
        TreeNode* cur = root;
        while (cur != nullptr || !stackn.empty()) {
            while (cur != nullptr) {
                res.push_back(cur->val); // 访问
                stackn.push(cur);
                cur = cur->left;
            }
            cur = stackn.top();
            stackn.pop();
            cur = cur->right;
        }
        return res;
    }
    // 后序，循环版
    vector<int> backorderTraversal(TreeNode* root) {
        vector<int> res = {};
        stack<TreeNode*> stackn;
        TreeNode* lastVisited = nullptr; // 记录上一次访问的节点
        if (!root) {
            return res;
        }
        TreeNode* cur = root;
        while (cur != nullptr || !stackn.empty()) {
            while (cur != nullptr) {
                stackn.push(cur);
                cur = cur->left;
            }
            cur = stackn.top();
            stackn.pop();
            // 如果右子树为空，或者右子树已经访问过
            if (cur->right == nullptr || cur->right == lastVisited) {
                res.push_back(cur->val); // 访问当前节点
                stackn.pop();
                lastVisited = cur; // 更新上一次访问的节点
                cur = nullptr; // 防止重复处理
            } else {
                cur = cur->right; // 转向右子树
            }
            cur = cur->right;
        }
        return res;
    }
};
