/// Source : https://leetcode-cn.com/problems/linked-list-cycle/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 环：链尾连接到某个位置。
// 用 set 装载遍历过的节点，遍历过程中查看节点 p 是否呗重复访问。
// 时间、空间复杂度都垫底。。。。
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> memo;
        auto p = head;
        while(p) {
            if(memo.find(p) != memo.end())
                return true;
            memo.insert(p);
            p = p->next;
        }
        return false;
    }
};

int main() {
    Solution test;
    vector<int> prices = {1, 2, 3, 4, 5};

    int res = test.maxProfit(prices);
    cout << res;

    return 0;
}
