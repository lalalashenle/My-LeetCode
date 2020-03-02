/// Source : https://leetcode-cn.com/problems/invert-binary-tree/
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
    void invert(TreeNode *root) {
        if(root) {
            swap(root->left, root->right);
            invert(root->left);
            invert(root->right);
        }
    }

public:
    TreeNode *invertTree(TreeNode *root) {
        invert(root);
        return root;
    }
};

int main() {


    return 0;
}
