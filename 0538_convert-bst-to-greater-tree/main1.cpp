/// Source : https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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

// 暴力算法，时间复杂度高，待优化 
class Solution {
private:
    vector<int> val_mark;
    int index = 0;
    
    void preFind(TreeNode* root) {
        if(root) {
        	val_mark.push_back(root->val);
        	preFind(root->left);
        	preFind(root->right);
		}
    }
    
    void changeVal(TreeNode* root) {
    	if(root) {
    		root->val = val_mark[index++];
    		changeVal(root->left);
    		changeVal(root->right);
		}
	}
public:
    TreeNode* convertBST(TreeNode* root) {
		preFind(root);
		vector<int> temp = val_mark;
		for(int i = 0; i < temp.size(); i++) 
			for(int j = 0; j < temp.size(); j++) 
				if(temp[j] > temp[i])
					val_mark[i] += temp[j]; 
		changeVal(root);
		return root;	
    }
};

int main() {


    return 0;
}
