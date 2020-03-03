/// Source : https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
/// Author : lalalashenle
/// Time   : 2020-03-03

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
    TreeNode* mirrorTree(TreeNode* root) {
		if(!root)
			return root;
		mirrorTree(root->left);
		mirrorTree(root->right);
		swap(root->left, root->right);
		
		return root;
    }
};

int main() {



    return 0;
}
