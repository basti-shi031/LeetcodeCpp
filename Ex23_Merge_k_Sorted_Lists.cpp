#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//finished
class Solution {
public:
	void eraseNull(vector<ListNode*>& lists)
	{
		auto iter = lists.begin();
		while (iter != lists.end()) {
			if (*iter == NULL ) {
				iter = lists.erase(iter);
			}
			else {
				++iter;
			}
		}
	}

	ListNode * mergeKLists(vector<ListNode*>& lists) {
		eraseNull(lists);

		ListNode head(0);
		ListNode *p = &head;
		while (lists.size()!=0)
		{
			int min = lists[0]->val;
			int minIndex = 0;
			int size = lists.size();
			for (int i = 0; i < size; i++)
			{
				if (lists[i]->val < min)
				{
					min = lists[i]->val;
					minIndex = i;
				}
			}
			p->next = lists[minIndex];
			p = p->next;
			lists[minIndex] = lists[minIndex]->next;
			if (lists[minIndex] == NULL)
			{
				lists.erase(lists.begin() + minIndex);
			}
		}
		return head.next;
	}
};

//int main() 
//{
//	vector<ListNode*> input;
//	ListNode* p1 = &ListNode(1);
//	ListNode* p2 = &ListNode(4);
//	ListNode* p3 = &ListNode(5);
//	p1->next = p2;
//	p2->next = p3;
//	input.push_back(p1);
//
//	ListNode* p4 = &ListNode(1);
//	ListNode* p5 = &ListNode(3);
//	ListNode* p6 = &ListNode(4);
//	p4->next = p5;
//	p5->next = p6;
//	input.push_back(p4);
//
//	ListNode* p7 = &ListNode(2);
//	ListNode* p8 = &ListNode(6);
//	p7->next = p8;
//	input.push_back(p7);
//
//	Solution so = Solution();
//	so.mergeKLists(input);
//}