/// Source : https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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

class Solution {
private:
    bool symmetric(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2)
            return true;
        else if (root1 && root2) {
            if (root1->val != root2->val)
                return false;
            return symmetric(root1->left, root2->right) && symmetric(root1->right, root2->left);
        } else return false;
    }

public:
    bool isSymmetric(TreeNode *root) {
        return symmetric(root, root);
    }
};

int main() {


    return 0;
}
