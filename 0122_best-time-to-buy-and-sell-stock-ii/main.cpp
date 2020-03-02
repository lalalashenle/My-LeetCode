/// Source : https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 动态规划思想。
// 现在可以多次买卖股票。
// 只要有获得利润的机会，就立即进行买卖，不放过任何一次可以赚钱的机会，这样子最后就能实现利润最大化。
class Solution { // [7,1,5,3,4,7,6,4]
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> memo(n, 0);
        int min_price = prices[0];
        for (int i = 1; i < n; i++) {
            memo[i] += memo[i - 1];
            if (prices[i] > prices[i - 1])
                memo[i] += (prices[i] - prices[i - 1]);
        }

        return memo[n - 1];
    }
};

int main() {
    Solution test;
    vector<int> prices = {1, 2, 3, 4, 5};

    int res = test.maxProfit(prices);
    cout << res;

    return 0;
}
