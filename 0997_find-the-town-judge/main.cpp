/// Source : https://leetcode-cn.com/problems/find-the-town-judge/
/// Author : lalalashenle
/// Time   : 2020-02-26

#include <iostream>
#include <vector>

using namespace std;

// 出度必须为 0 ，入度必须为 N-1
class Solution {
public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> memo_out(N + 1, 0); // [1.....N]
        vector<int> memo_in(N + 1, 0);
        int n = trust.size();
        for (int i = 0; i < n; i++) {
            memo_out[trust[i][0]]++;
            memo_in[trust[i][1]]++;
        }
        for (int i = 1; i < memo_out.size(); i++) {
            if (memo_out[i] == 0 && memo_in[i] == N - 1)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution test;
    vector<vector<int>> trust = {{1, 2},
                                 {2, 3}};
    int N = 3;
    int ans = test.findJudge(N, trust);

    cout << ans;
    return 0;
}
