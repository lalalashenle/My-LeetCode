/// Source : https://leetcode-cn.com/problems/coin-change/
/// Author : lalalashenle
/// Time   : 2020-03-09 

#include <iostream>
#include <vector>

using namespace std;

// 记忆化搜索，尼玛的还是超时
class Solution {
	
private:
	vector<int> memo;
	int tryChange(vector<int>& coins, int amount, int tmp) {
		if(amount == 0)
			return 0;
		if(amount < 0)
			return tmp + 1;
		if(memo[amount] != tmp + 1)
			return memo[amount];
		int min_ans = tmp + 1;
		for(int i = 0; i < coins.size(); i++)
			min_ans = min( 1 + tryChange(coins, amount - coins[i], tmp), min_ans) ;
		memo[amount] = min_ans;
		return min_ans;
	}	
	
public:
    int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		int tmp = amount;
		memo = vector<int>(amount + 1, amount + 1);
		int ans = tryChange(coins, amount, tmp);
		return (ans > tmp) ? -1 : ans;
    }
};

int main() {
    Solution test;
    int amount = 6249;
    vector<int> coins = {186, 419, 83, 408};

    cout << test.coinChange(coins, amount);
    
    return 0;
}
