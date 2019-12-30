//
// Created by Basti031 on 2019/12/10.
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        while(head->val==val)
        {
            head=head->next;
            if(!head)
                return NULL;
        }
        ListNode* tmp=head;
        while(tmp && tmp->next)
        {
            if (tmp->next->val==val)
                tmp->next=tmp->next->next;
            else
                tmp=tmp->next;
        }
        return head;
    }
};