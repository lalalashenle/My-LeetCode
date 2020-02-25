/// Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 动态规划思想。
// 遍历过程中记录 prices 的最小值，改良状态转移方程
// memo[i] = max(memo[i - 1], prices[i] - min_price);
// 从而将时间复杂度压缩至 O(n)
class Solution { // [7,1,5,3,6,4]
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n == 0)
            return 0;

        vector<int> memo(n, 0);

        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            memo[i] = max(memo[i - 1], prices[i] - min_price);
            if (min_price > prices[i])
                min_price = prices[i];
        }
        return memo[n - 1];
    }
};

int main() {
    Solution test;
    vector<int> prices = {7,1,5,3,6,4};

    int res = test.maxProfit(prices);
    cout << res;

    return 0;
}
