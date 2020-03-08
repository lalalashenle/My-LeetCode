/// Source : https://leetcode-cn.com/problems/partition-equal-subset-sum/
/// Author : lalalashenle
/// Time   : 2020-03-08

#include <iostream>
#include <vector>

using namespace std;

// 0-1 背包问题。 
class Solution {
private:
	bool partition(vector<int>& nums, int sum) {
		int n = nums.size();
		vector<bool> memo(sum + 1, false);
		for(int i = 0; i <= sum; i++)
			memo[i] = (nums[0] == i) ? true : false;
			
		for(int i = 1; i < n; i++) {
			for(int j = sum; j >= nums[i]; j--)
				memo[j] = (memo[j - nums[i]]) || memo[j];
		}
		
		return memo[sum];
	}
public:
    bool canPartition(vector<int>& nums) {
		int sum = 0;
		for(auto e : nums)
			sum += e;
		if(sum % 2) 
			return false;
		return partition(nums, sum/2);
    }
};

int main() {
    Solution test;
    vector<int> nums = {1, 2, 3, 5, 1, 2, 1000};
    cout << test.canPartition(nums);
    
    return 0;
}



