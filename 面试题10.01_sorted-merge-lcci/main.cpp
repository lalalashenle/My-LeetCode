/// Source : https://leetcode-cn.com/problems/sorted-merge-lcci/
/// Author : lalalashenle
/// Time   : 2020-03-03

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
		int index = m;
		for(int i = 0; i < n; i++)
			A[index++] = B[i];
		sort(A.begin(), A.begin() + (m + n));
    }
};

int main() {
	Solution test;
	int m = 3, n = 3;
	vector<int> A = {1,2,3,0,0,0};
	vector<int> B = {2,5,6};
	test.merge(A, m, B, n);
	
	for(auto e : A)
		cout << e << " ";

    return 0;
}
