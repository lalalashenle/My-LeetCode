/// Source : https://leetcode-cn.com/problems/distribute-candies-to-people/
/// Author : lalalashenle
/// Time   : 2020-03-05

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
		int num_can = 1;
		vector<int> child(num_people, 0);
		for(int i = 0; i < num_people; i++) {
			if(candies - num_can >= 0) {
				child[i] += num_can;
				candies -= num_can;
			} else {
				child[i] += candies;
				break;
			}
			num_can++;
			if(i == num_people - 1)
				i = -1;
				
		}
		return child;
    }
};

int main() {
	Solution test;
	int candies = 0, num_people = 4;
	vector<int> res = test.distributeCandies(candies, num_people);
	for(auto e : res)
		cout << e << " ";

	return 0;
}

