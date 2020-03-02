/// Source : https://leetcode-cn.com/problems/univalued-binary-tree/
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
    bool unival(TreeNode *root, int temp) {
        if (!root)
            return true;
        if (root->val != temp)
            return false;
        return unival(root->left, temp) && unival(root->right, temp);
    }

public:
    bool isUnivalTree(TreeNode *root) {
        if (!root)
            return true;
        int temp = root->val;
        return unival(root, temp);
    }
};

int main() {


    return 0;
}
