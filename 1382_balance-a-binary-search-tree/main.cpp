/// Source : https://leetcode-cn.com/problems/balance-a-binary-search-tree/
/// Author : lalalashenle
/// Time   : 2020-04-28

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
   public:
    vector<int> midArr;  // 中序遍历得到的有序序列
    TreeNode* balanceBST(TreeNode* root) {
        midSort(root);

        // 二分查找建树
        int left = 0, right = midArr.size() - 1;

        return binSerach(left, right);
    }

    void midSort(TreeNode* root) {
        if (root) {
            midSort(root->left);
            midArr.push_back(root->val);
            midSort(root->right);
        }
    }

    TreeNode* binSerach(int left, int right) {
        if (left > right) {
            return NULL;
        }

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(midArr[mid]);
        root->left = binSerach(left, mid - 1);
        root->right = binSerach(mid + 1, right);

        return root;
    }
};
