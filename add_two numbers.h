/*
You are given two non-empty linked lists representing two non-negative integers. The digits 
are stored in reverse order and each of their nodes contain a single digit. Add the two numbers
and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
*/

#ifndef _LEETCODE_ADD_TWO_NUMBERS_H
#define _LEETCODE_ADD_TWO_NUMBERS_H

#include <cstdio>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers_mark1(ListNode *l1, ListNode *l2)
{
	int sum = l1->val + l2->val;
	int digit = sum % 10;
	int carry = (sum - digit) / 10;
	l1 = l1->next;
	l2 = l2->next;

	ListNode *head = new ListNode(digit);
	ListNode *p = head;
	while (l1 && l2) {
		sum = l1->val + l2->val + carry;
		digit = sum % 10;
		carry = (sum - digit) / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	
	if (!l1)
		l1 = l2;
	while (l1) {
		sum = l1->val + carry;
		digit = sum % 10;
		carry = (sum - digit) / 10;
		p->next = new ListNode(digit);
		p = p->next;
		l1 = l1->next;
	}

	if (carry)
		p->next = new ListNode(carry);

	return head;
}

ListNode* addTwoNumbers_mark2(ListNode *l1, ListNode *l2) 
{
	ListNode *head = new ListNode(0);
	ListNode *p = head, *q = nullptr;
	int carry = 0;
	while (l1 || l2) {
		int x = l1 ? l1->val : 0;
		int y = l2 ? l2->val : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		q = new ListNode(sum % 10);
		p->next = q;
		p = p->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry)
		p->next = new ListNode(carry);
	return head->next;
}

void debug_print(const ListNode *head)
{
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}

#endif // !_LEETCODE_ADD_TWO_NUMBERS_H