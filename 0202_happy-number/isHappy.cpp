/// Source : https://leetcode-cn.com/problems/happy-number/submissions/
/// Author : lalalashenle
/// Time   : 2020-02-24

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// set记录结果，出现重复则结束死循环。
class Solution {
public:
    bool isHappy(int n) {
        set<int> memo;
        while(1) {
            if(memo.find(n) != memo.end())
                return false;
            else {
                memo.insert(n);
                n = HappyFunc(n);
            }
            if(n == 1)
                return true;
        }
    }

    int HappyFunc(int n) {
        int res = 0;
        while(n > 0) {
            res += (n%10)*(n%10);
            n /= 10;
        }
        return res;
    }
};

int main() {
    Solution test;
    bool ans = test.isHappy(2);
    cout << ans;

    return 0;
}
