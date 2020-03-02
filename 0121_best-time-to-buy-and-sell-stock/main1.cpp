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
// 时间复杂度超时。需优化。
class Solution { // [7,1,5,3,6,4]
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<int> memo(n, 0);
        int max_res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                memo[i] = max(memo[i], prices[i] - prices[j]);
            max_res = max(max_res, memo[i]);
        }
        return max_res;
    }
};

int main() {
    Solution test;
    vector<int> prices = {7,6,4,3,1};

    int res = test.maxProfit(prices);
    cout << res;

    return 0;
}
