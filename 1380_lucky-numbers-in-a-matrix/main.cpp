/// Source : https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/
/// Author : lalalashenle
/// Time   : 2020-04-27

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);     // 第几行的最小值在第几列
        vector<int> column(n, 0);  // 第几列的最大值在第几行

        for (int i = 0; i < m; i++) {
            int tpm_min = 99999;
            for (int j = 0; j < n; j++) {
                if (tpm_min > matrix[i][j]) {
                    tpm_min = matrix[i][j];
                    row[i] = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int tmp_max = 0;
            for (int j = 0; j < m; j++) {
                if (tmp_max < matrix[j][i]) {
                    tmp_max = matrix[j][i];
                    column[i] = j;
                }
            }
        }

        vector<int> ret;
        int index = 0;
        if (m < n) {  // 行小于列
            while (index < m) {
                if (column[row[index]] == index)
                    ret.push_back(matrix[index][row[index]]);
                index++;
            }
        } else {
            while (index < n) {
                if (row[column[index]] == index)
                    ret.push_back(matrix[column[index]][index]);
                index++;
            }
        }

        return ret;
    }
};

int main() {
    Solution test;
    vector<vector<int>> mat = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<int> res = test.luckyNumbers(mat);
    for (int e : res)
        cout << e << " ";
    return 0;
}
