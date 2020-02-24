/// Source : https://leetcode-cn.com/problems/rotate-array/
/// Author : lalalashenle
/// Time   : 2020-2月

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

void swap(int &m, int &n) {
    int temp = m;
    m = n;
    n = temp;
}

// 先整体翻转，再局部翻转，考研常见题。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        if(k >= n)
            k = k % n;
        for(int i = 0; i < n/2; i++)
            swap(nums[i], nums[n-i-1]);
        for(int i = 0; i < k/2; i++)
            swap(nums[i], nums[k-i-1]);
        for(int i = k; i < (n+k)/2; i++)
            swap(nums[i], nums[n-i+k-1]);
    }
};

int main() {
    Solution test;
    vector<int> num = {1,2,3,4,5,6,7};
    int k = 3;
    test.rotate(num, k);
    for(auto a : num)
        cout << a;

    return 0;
}
