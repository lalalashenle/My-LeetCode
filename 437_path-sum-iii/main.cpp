/// Source : https://leetcode-cn.com/problems/path-sum-iii/
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

// 前序遍历。
// 依次计算每个结点的符合题意的数量。相加即可。
class Solution {
private:
    vector<TreeNode *> memo;
    int counter = 0;
public:
    int pathSum(TreeNode *root, int sum) {
        preFind(root); // 先把结点收集起来
        for (int i = 0; i < memo.size(); i++) { // 遍历每个结点
            sumRoot(memo[i], sum);
        }
        return counter;

    }

    void sumRoot(TreeNode *root, int sum) {  // [1, -2, -3, 1, 3, -2, null, -1]  -1
        if (!root)
            return;
        else {
            sum -= root->val;
            if (sum == 0)
                counter++;
            sumRoot(root->left, sum);
            sumRoot(root->right, sum);
        }
    }

    void preFind(TreeNode *root) {
        if (root) {
            memo.push_back(root);
            preFind(root->left);
            preFind(root->right);
        }
    }
};

int main() {
    Solution test;
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    int ans = test.minimumTotal(triangle);
    cout << ans;
    return 0;
}
