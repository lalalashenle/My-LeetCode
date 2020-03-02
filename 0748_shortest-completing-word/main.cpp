/// Source : https://leetcode-cn.com/problems/shortest-completing-word/
/// Author : lalalashenle
/// Time   : 2020-02-27

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// map。都一个减一个加判断。
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        map<char, int> memo;
        for (int i = 0; i < licensePlate.size(); i++) {
            if (licensePlate[i] >= 'a' && licensePlate[i] <= 'z')
                memo[licensePlate[i]]++;
            if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z')
                memo[licensePlate[i] + 32]++;
        }
        vector<int> memo_length(words.size(), 0);
        vector<bool> istrue(words.size(), true);
        string ans = "1";
        int minlength = 999;
        for (int i = 0; i < words.size(); i++) {
            memo_length[i] = words[i].size();
            map<char, int> temp = memo;
            for (int j = 0; j < words[i].size(); j++)
//                if(words[i][j] >= 'a' && words[i][j <= 'z')
//                    words[i][j] -= 32;
                if (temp.find(words[i][j]) != temp.end())
                    temp[words[i][j]]--;
            map<char, int>::iterator it = temp.begin();
            for (int k = 0; k < temp.size(); k++, it++)
                if (it->second > 0)
                    istrue[i] = false;

            if (minlength > memo_length[i] && istrue[i] == true) {
                minlength = memo_length[i];
                ans = words[i];
            }
        }

        return ans;
    }
};

int main() {
    Solution test;
    string licensePlate = "1s3 456";
    vector<string> words = {"looks", "pest", "stew", "show"};

    string ans = test.shortestCompletingWord(licensePlate, words);
    cout << ans;

    return 0;
}
