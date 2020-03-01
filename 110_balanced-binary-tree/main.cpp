/// Source : https://leetcode-cn.com/problems/balanced-binary-tree/
/// Author : lalalashenle
/// Time   : 2020-03-1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 平衡二叉树：每个节点的左右两个子树的高度差的绝对值不超过 1
// 如果结点空，显然平衡。
// 否则：当左结点与右结点都平衡，且左右结点高度差不超过 1时，平衡。其余情况不平衡。
class Solution {
private:
    int height(TreeNode *root) {
        if (!root)
            return 0;
        return max(1 + height(root->left), 1 + height(root->right));
    }

    bool balance(TreeNode *root) {
        if (!root)
            return true;
        int hl = height(root->left), hr = height(root->right);
        bool b = balance(root->left) && balance(root->right);
        if (b && (abs(hl - hr) <= 1))
            return true;
        return false;
    }

public:
    bool isBalanced(TreeNode *root) {

        return balance(root);
    }
};

int main() {


    return 0;
}
