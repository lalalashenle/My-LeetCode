/// Source : https://leetcode-cn.com/problems/same-tree/
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        else if (p && q) {
            if (q->val != p->val)
                return false;
            else
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else
            return false;
    }
};

int main() {


    return 0;
}
