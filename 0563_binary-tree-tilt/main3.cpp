/// Source : https://leetcode-cn.com/problems/binary-tree-tilt/
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
    int sum = 0;

    int sumVal(TreeNode *root) {
        if (!root)
            return 0;
        int a = sumVal(root->left);
        int b = sumVal(root->right);
        sum += abs(a - b);
        return a + b + root->val;
    }

public:
    int findTilt(TreeNode *root) {
        sumVal(root);
        return sum;
    }
};

int main() {


    return 0;
}
