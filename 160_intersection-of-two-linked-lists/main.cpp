/// Source : https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
/// Author : lalalashenle
/// Time   : 2020-02-25

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// set保存 pA 元素。
// 遍历 pB ，查看是否与set中的元素重合。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> memo;
        auto pA = headA, pB = headB;
        while(pA) {
            memo.insert(pA);
            pA = pA->next;
        }
        while(pB) {
            if(memo.find(pB) != memo.end())
                return pB;
            else
                pB = pB->next;
        }
        return nullptr;
    }
};
