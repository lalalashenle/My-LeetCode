/// Source : https://leetcode-cn.com/problems/trim-a-binary-search-tree/
/// Author : lalalashenle
/// Time   : 2020-03-02

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		if(!root)
			return NULL;
			
		if(root->val < L)
			return trimBST(root->right, L, R);
		if(root->val > R)
			return trimBST(root->left, L, R);
			
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		
		return root;
    }
};

int main() {


    return 0;
}
