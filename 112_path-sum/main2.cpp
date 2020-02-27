/// Source : https://leetcode-cn.com/problems/path-sum/
/// Author : lalalashenle
/// Time   : 2020-02-27

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//
class Solution {

public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root && sum == 0)
            return false;
        bool ans = PathSum(root, sum);
        return ans;

    }

    bool PathSum(TreeNode *root, int sum) {

        if (root) {
            sum -= root->val;
            if (!root->right && !root->left)
                return (sum == 0);
            else
                return PathSum(root->left, sum) || PathSum(root->right, sum);
        } else
            return false;
    }
};

int main() {

    return 0;
}
