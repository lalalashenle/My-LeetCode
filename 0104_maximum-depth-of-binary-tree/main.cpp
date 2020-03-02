/// Source : https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
/// Author : lalalashenle
/// Time   : 2020-02-28

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        else {
            return max(1 + maxDepth(root->left), 1 + maxDepth(root->right));
        }
    }
};

int main() {
    

    return 0;
}
