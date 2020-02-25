/// Source : https://leetcode-cn.com/problems/count-primes/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 筛选法。
// 好厉害，膜拜。
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int counter = 0;
        vector<bool> memo(n,true);  // [2 , n-1]
        // cout << "size = " << memo.size();

        for (int i = 2; i < n; i++) {
            if (memo[i] == true) {
                counter++;
                for (int j = 2 * i; j < n; j += i)
                    memo[j] = false;
            }
        }
        return counter;
    }
};

int main() {
    Solution test;
    int x = 1000;
    int ans = test.countPrimes(x);

    cout << ans;

    return 0;
}
