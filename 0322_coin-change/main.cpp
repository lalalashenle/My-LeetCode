/// Source : https://leetcode-cn.com/problems/coin-change/
/// Author : lalalashenle
/// Time   : 2020-03-09 

#include <iostream>
#include <vector>

using namespace std;

// 自底向上，动态规划。
class Solution {
	
public:
    int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<int> memo(amount + 1, amount + 1);
		memo[0] = 0;
		for(int i = 1; i <= amount; i++) {
			int min_ans = amount + 1; 
			for(int j = 0; j < n; j++)
				if(i >= coins[j])
					min_ans = min(min_ans, 1 + memo[i - coins[j]]);
			memo[i] = min_ans;
		}
		
		for(auto e : memo)
			cout << e << " ";
		cout << endl;
		
		if(memo[amount] > amount)
			return -1;
		else return memo[amount];
    }
};

int main() {
    Solution test;
    int amount = 11;
    vector<int> coins = {1, 2, 5};

    cout << test.coinChange(coins, amount);
    
    return 0;
}
