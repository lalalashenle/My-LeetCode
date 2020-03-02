/// Source : https://leetcode-cn.com/problems/valid-perfect-square/
/// Author : lalalashenle
/// Time   : 2020-02-24

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 利用二分法思想，降低时间复杂度
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;

            if ((long long)mid * mid == num)
                return true;
            else if ((long long)mid * mid > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution test;
    int num = 2147483647;
    bool ans = test.isPerfectSquare(num);
    cout << ans;

    return 0;
}
