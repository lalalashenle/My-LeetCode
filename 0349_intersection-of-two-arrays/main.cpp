/// Source : https://leetcode-cn.com/problems/intersection-of-two-arrays/
/// Author : lalalashenle
/// Time   : 2020-02-24

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// set存放一个数集，遍历另一个数集并比对是否与前数集产生了交集
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ans;
        set<int> memo, temp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++) {
            memo.insert(nums1[i]);
        }
        for (int j = 0; j < n2; j++) { // memo里找得到，同时temp里找不到
            if (memo.find(nums2[j]) != memo.end() && temp.find(nums2[j]) == temp.end()) {
                ans.push_back(nums2[j]);
                temp.insert(nums2[j]);
            }

        }
        return ans;
    }
};

int main() {
    Solution test;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> num = test.intersection(nums1, nums2);
    for(auto a : num)
        cout << a << " ";

    return 0;
}
