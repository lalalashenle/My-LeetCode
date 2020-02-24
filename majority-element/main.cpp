/// Source : https://leetcode-cn.com/problems/majority-element/
/// Author : lalalashenle
/// Time   : 2020-2月

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 创建map，记录各元素数量，然后返回其中最大数量对应的结果。
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        map<int, int> memo;
        for(int i = 0; i < n; i++)
            memo[nums[i]]++;
        map<int, int> :: iterator it = memo.begin();
        int max_index = -1;
        int ans = 0;
        for(; it != memo.end(); it++) {
            if(max_index < it->second) {
                max_index = it->second;
                ans = it->first;
            }
        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums = {2,2,1,1,1,2,2};
    int ans = test.majorityElement(nums);

    cout << ans;

    return 0;
}
