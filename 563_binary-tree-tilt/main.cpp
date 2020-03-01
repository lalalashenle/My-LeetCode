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
    int res;

    int sumVal(TreeNode *root) {

        if (root) {
            res += root->val;
            sumVal(root->left);
            sumVal(root->right);
        }
        return res;
    }

//    int sumTilt(TreeNode *root) { // 计算每个结点的坡度
//        if (!root)
//            return 0;
//        return abs(sumVal(root->left) - sumVal(root->right));
//    }

public:
    int findTilt(TreeNode *root) {
        if (!root)
            return 0;
        res = 0;
        int a = sumVal(root->left);
        res = 0;
        int b = sumVal(root->right);
        sum += abs(a - b);
        findTilt(root->left);
        findTilt(root->right);
        return sum;
    }
};

int main() {


    return 0;
}
