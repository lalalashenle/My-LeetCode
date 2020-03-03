/// Source : https://leetcode-cn.com/problems/add-two-numbers/
/// Author : lalalashenle
/// Time   : 2020-03-03

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution { // [1], [9, 9]
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* L = new ListNode(0);
		ListNode* p = L;
		int flag = 0;
		while(l1 && l2) {
			if(l1->val + l2->val + flag >= 10) {
				ListNode* node = new ListNode(l1->val + l2->val+ flag - 10);
				flag = 1;
				p->next = node;
				p = node;
				l1 = l1->next;
				l2 = l2->next;
			} else {
				ListNode* node = new ListNode(l1->val + l2->val + flag);
				flag = 0;
				p->next = node;
				p = node;
				l1 = l1->next;
				l2 = l2->next;
			}
		}
		if(l1)
			l2 = l1;
		while(l2) {
			if(l2->val + flag >= 10) {
				ListNode* node = new ListNode(l2->val+ flag - 10);
				flag = 1;
				p->next = node;
				p = node;
				l2 = l2->next;
			} else {
				ListNode* node = new ListNode(l2->val + flag);
				flag = 0;
				p->next = node;
				p = node;
				l2 = l2->next;
			}
		}
		if(flag > 0) {
			ListNode* node = new ListNode(flag);
			p->next = node;
			p = node;
		}
			
		return L->next;
	}
};

int main() {




	return 0;
}
