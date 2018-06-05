#include<iostream>
#include<iostream>

using namespace std;

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//finished
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode * firstIndex = head;
		ListNode * deleteIndex = head;
		int index = 0;
		//fIndex提前先走N步
		while (index<n-1&&firstIndex)
		{
			firstIndex = firstIndex->next;
			index++;
		}
		if (firstIndex == NULL)
		{
			return NULL;
		}

		ListNode * prev = head;
		while (firstIndex->next!=NULL)
		{
			firstIndex = firstIndex->next;
			deleteIndex = deleteIndex->next;
			if (firstIndex->next !=NULL&& firstIndex->next->next == NULL)
			{
				prev = deleteIndex;
			}
		}
		if (deleteIndex == head)
		{
			return head->next;
		}

		prev->next = deleteIndex->next;
		delete(deleteIndex);

		return head;
	}
};

//int main()
//{
//	ListNode five = ListNode(5);
//	ListNode four = ListNode(4);
//	ListNode three = ListNode(3);
//	ListNode two = ListNode(2);
//	ListNode one = ListNode(1);
//
//	four.next = &five;
//	three.next = &four;
//	two.next = &three;
//	one.next = &two;
//	Solution so = Solution();
//	so.removeNthFromEnd(&one, 2);
//
//}