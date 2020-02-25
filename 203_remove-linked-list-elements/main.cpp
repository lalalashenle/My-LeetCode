/// Source : https://leetcode-cn.com/problems/remove-linked-list-elements/
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

class Solution { // L->1->2->6->6->3->4->5->6
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto L = new ListNode(0);
        L->next = head;
        auto p = L;
        while(p->next) {
            if(p->next->val == val) {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return L->next;
    }
};

int main() {

    return 0;
}
