/// Source : https://leetcode-cn.com/problems/diameter-of-binary-tree/
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
private:
	int res = 0;
	int height(TreeNode* root) {
		if(!root)
			return 0;
		
		int height_l = height(root->left);
		int height_r = height(root->right);
		if(height_l + height_r > res)
			res = height_l + height_r;	
			
		return return max(1+height_l, 1+height_r);
	}	
public:
    int diameterOfBinaryTree(TreeNode* root) {
    	if(!root)
    		return 0;
    	height(root);
		
		return res;
    }
};

int main() {


    return 0;
}
