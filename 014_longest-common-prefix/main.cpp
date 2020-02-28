/// Source : https://leetcode-cn.com/problems/longest-common-prefix/
/// Author : lalalashenle
/// Time   : 2020-02-28

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

//
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];
        int i, j = 0;
        int jud;
        int min_length = INT64_MAX;
        for (int m = 0; m < strs.size(); m++)
            if (min_length > strs[m].length())
                min_length = strs[m].length();
        while ( j < min_length )
        {
            jud = 1;
            for (i = 1; i < strs.size(); i++)
                if (strs[i][j] != strs[i - 1][j])
                    jud = 0;
            if (jud == 1)
                res += strs[0][j];
            else break;
            j++;
        }
        return res;
    }
};

int main() {
    Solution test;
    vector<string> strs = {"flower","flow","flight"};
    cout << test.longestCommonPrefix(strs);

    return 0;
}
