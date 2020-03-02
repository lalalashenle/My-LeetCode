/// Source : https://leetcode-cn.com/problems/triangle/
/// Author : lalalashenle
/// Time   : 2020-02-26

#include <iostream>
#include <vector>

using namespace std;

// 最小路径
// 动态规划
// 状态转移方程： memo[j] = min(triangle[i][j] + memo[j], triangle[i][j] + memo[j + 1]);
// 从后到前
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        if (n == 1)
            return triangle[0][0];
        vector<int> memo(n, 0); // [0.....n-2]
        for (int i = 0; i < n; i++)
            memo[i] = triangle[n - 1][i];
        // memo[0] = triangle[0][0];
        for (int i = n - 2; i >= 0; i--) { // 第 i 行
            for (int j = 0; j <= i; j++) {
                memo[j] = min(triangle[i][j] + memo[j],
                              triangle[i][j] + memo[j + 1]);
            }
        }

        return memo[0];
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
