/// Source : https://leetcode-cn.com/problems/merge-two-binary-trees/
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
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2)
            return NULL;

        TreeNode* root;
        if (t1 && t2) {
            root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
        } else if (t1 && !t2) {
            root = t1;
            root->left = mergeTrees(t1->left, NULL);
            root->right = mergeTrees(t1->right, NULL);
        } else {
            root = t2;
            root->left = mergeTrees(NULL, t2->left);
            root->right = mergeTrees(NULL, t2->right);
        }

        return root;
    }
};

int main() {


    return 0;
}
