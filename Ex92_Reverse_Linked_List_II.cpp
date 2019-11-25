//
// Created by Basti031 on 2019/11/19.
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

    ListNode *reverseBetween(ListNode *head, int m, int n) {

        if (head == NULL || head->next == NULL || m >= n) {
            return head;
        }

        ListNode dummyNode = ListNode(0);
        dummyNode.next = head;
        head = &dummyNode;

        ListNode *preNode = head; // pre node

        for (int i = 1; i < m; i++) {
            preNode = preNode->next;
        }

        // ----

        ListNode *tempNode = preNode->next;

        stack<ListNode> s;
        int i = 0;
        while (m + i <= n) {
            s.push(*tempNode);
            tempNode = tempNode->next;
            i++;
        }

        ListNode *postNode = tempNode; // post node

        ListNode resultNode = s.top();
        s.pop();
        tempNode = &resultNode;

        while (!s.empty()) {
            tempNode->next = &s.top();
            s.pop();
            tempNode = tempNode->next;
        }

        //
        preNode->next = &resultNode;
        tempNode->next = postNode;

        ListNode *result = dummyNode.next;

        return &dummyNode;


    }
};

int main() {
    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);
    ListNode n5 = ListNode(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    Solution solution = Solution();
    ListNode *a = solution.reverseBetween(&n1, 2, 4);
    int b = 1;
}

