/// Source : https://leetcode-cn.com/problems/count-primes/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// 经典素数算法
// 不幸超时，需优化
class Solution {
public:
    int countPrimes(int n) {
        int counter = 0;
        for (int i = 2; i < n; i++)
            if (isPrimes(i))
                counter++;

        return counter;
    }

private:
    bool isPrimes(int n) {
        for (int i = 2; i * i < n + 1; i++)
            if (n % i == 0)
                return false;
        return true;
    }
};

int main() {
    Solution test;
    int x = 10;
    int ans = test.countPrimes(10);

    cout << ans;

    return 0;
}
