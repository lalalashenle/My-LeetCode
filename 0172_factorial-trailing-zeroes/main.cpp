/// Source : https://leetcode-cn.com/problems/factorial-trailing-zeroes/
/// Author : lalalashenle
/// Time   : 2020-02-24

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 数学题。
// 零是有2*5构成的，所以要求数尾的零，就要求2*5的个数（其实主要就是5的个数），即每次遍历 res += n/5
// 需要注意的是，类似25=5*5，一个数包含不知一个5。
class Solution {
//public:
//    long long trail(int n) {
//        long long res = 1;
//        for (int i = n; i >= 1; i--)
//            res *= i;
//        return res;
//    }

public:
    int trailingZeroes(int n) {

        int res = 0;
        while (n >= 5) {
            res += n / 5;
            n /= 5;
        }
        return res;

    }
};

int main() {
    Solution test;
    int n = 30;
    //long long ans = test.trail(n);
    int ans = test.trailingZeroes(n);

    cout << ans;

    return 0;
}
