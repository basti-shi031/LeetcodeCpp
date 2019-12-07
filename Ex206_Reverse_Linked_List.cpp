//
// Created by Basti031 on 2019/12/7.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {

        if (!head) {
            return NULL;
        }

        ListNode *p = head;
        stack<ListNode *> s;

        while (p != NULL) {
            s.push(p);
            p = p->next;
        }

        ListNode *newHead = s.top();
        s.pop();
        ListNode *q = newHead;
        while (!s.empty()) {
            ListNode *top = s.top();
            s.pop();
            q->next = top;
            q = q->next;
        }
        q->next = NULL;

        return newHead;
    }
};

/*
int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    n1.next = &n2;

    Solution solution = Solution();
    ListNode *a = solution.reverseList(&n1);
    int b = 1;
}*/
