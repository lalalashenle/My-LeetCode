/// Source : https://leetcode-cn.com/problems/symmetric-tree/
/// Author : lalalashenle
/// Time   : 2020-02-27

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return _isSym(root, root);
    }

    bool _isSym(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2)
            return true;
        else if (root1 && root2) {
            if (root1->val != root2->val)
                return false;
            else {
                return _isSym(root1->left, root2->right) && _isSym(root1->right, root2->left);
            }
        } else
            return false;
    }
};

int main() {


    return 0;
}
