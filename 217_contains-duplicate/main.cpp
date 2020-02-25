/// Source : https://leetcode-cn.com/problems/contains-duplicate/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// map 记录元素。 遍历过程中查看元素数量是否大于 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> memo;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            memo[nums[i]]++;
            if(memo[nums[i]] > 1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool ans = test.containsDuplicate(nums);

    cout << ans;

    return 0;
}
