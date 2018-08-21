//
// Created by Basti031 on 2018/8/21.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* new_node = new ListNode(0);
        new_node->next = head;

        ListNode* pre = new_node;
        ListNode* curr = head;
        ListNode* move = head;

        while (curr != NULL && curr->val < x)
        {
            move = curr;
            pre = curr;
            curr = curr->next;
        }

        while (curr != NULL)
        {
            if (curr->val >= x)
            {
                move = curr;
                curr = curr->next;
            }
            else if(curr->val < x)
            {
                move->next = curr->next;
                curr->next = pre->next;
                pre->next = curr;

                pre = curr;
                curr = move->next;
            }
        }
        ListNode* temp = new_node;
        delete new_node;
        return temp->next;
    }
};