//
// Created by Basti031 on 2018/7/20.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};


class Solution {
public:
    int length(ListNode *head) {
        int i = 0;
        ListNode *p = head;
        while (p != NULL) {
            p = p->next;
            i++;
        }
        return i;
    }

    ListNode *rotateRight2(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *slower = head;
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        int index = 0;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
            if (index > 0) {
                slower = slower->next;
            }
            index++;
        }
        fast->next = head;
        slower->next = NULL;
        return slow;
    }

    ListNode* rotateRight(ListNode *head, int k) {
        int size = length(head);
        if (size == 0 || size == 1) {
            return head;
        }
        k = k % size;
        return rotateRight2(head, k - 1);
    }
};

/*
int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);
    ListNode n5 = ListNode(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution solution = Solution();
    solution.rotateRight(&n1,2);
}*/
