/// Source : https://leetcode-cn.com/problems/pascals-triangle/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 动态规划
// 状态转移方程：memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j]
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > memo(numRows);
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1},
                    {1, 1}};
        for (int i = 0; i < numRows; i++)
            memo[i] = vector<int>(i + 1, 1);
        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++)
                memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
        }
        return memo;
    }
};

int main() {
    Solution test;
    int i = 5;
    vector<vector<int> > ans = test.generate(i);

    for(int m = 0; m < ans.size(); m++) {
        for (int n = 0; n < ans[m].size(); n++)
            cout << ans[m][n] << " ";
        cout << endl;
    }

    return 0;
}
