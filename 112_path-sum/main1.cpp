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
private:
    int counter = 0;
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root && sum == 0)
            return false;
        PathSum(root, sum);
        if (counter > 0)
            return true;
        return false;
    }

    void PathSum(TreeNode *root, int sum) {
        if (!root)
            return;
        if (root) {
            sum -= root->val;
            if (sum == 0 && !root->left && !root->right)
                counter++;
            PathSum(root->left, sum);
            PathSum(root->right, sum);
        }
    }
};

int main() {

    return 0;
}
