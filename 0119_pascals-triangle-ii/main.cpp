/// Source : https://leetcode-cn.com/problems/pascals-triangle-ii/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 在O(k)的空间里动态模拟杨辉三角的形成过程。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> memo;
        for(int i = 0; i <= rowIndex; i++){
            memo.push_back(1);
            for(int j = i-1; j > 0; j--)
                memo[j] += memo[j-1];
        }
        return memo;
    }
};

int main() {
    Solution test;
    int i = 5;
    vector<int> ans = test.getRow(i);

    for(auto e : ans)
        cout << e << " ";

    return 0;
}
