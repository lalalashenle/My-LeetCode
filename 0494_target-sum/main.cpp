/// Source : https://leetcode-cn.com/problems/target-sum/
/// Author : lalalashenle
/// Time   : 2020-03-10 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	if(S > 1000 || S < -1000)
    		return 0;
		int n = nums.size();
		vector<vector<int> > memo(n, vector<int>(2001, 0)); // 和的取值范围：[-1000, 1000] 
		memo[0][nums[0] + 1000] = 1;
		memo[0][-nums[0] + 1000] += 1; // 非常关键。 nums[0] + 1000 和 -nums[0] + 1000 可能相同    // [0,0,0,0,0,0,0,1]
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < 2001; j++) {
				if(j + nums[i] >= 0 && j + nums[i] < 2001)
					memo[i][j] += memo[i - 1][j + nums[i]];
				if(j - nums[i] >= 0 && j - nums[i] < 2001)
					memo[i][j] += memo[i - 1][j - nums[i]];
			}
		}
		
		return memo[n - 1][S + 1000];
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 1, 1, 1, 1};
	int S = 3; 
	cout << test.findTargetSumWays(nums, S);
    
    return 0;
}
