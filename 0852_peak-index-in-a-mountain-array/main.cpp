/// Source : https://github.com/lalalashenle/My-LeetCode/blob/master/0001_two-sum/main
/// Author : lalalashenle
/// Time   : 2021-1月

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int len = arr.size();
        for (int i = 0; i < len; i++) {
            if (arr[i] > arr[i + 1])
                return i;
        }
        return 0;
    }
};


