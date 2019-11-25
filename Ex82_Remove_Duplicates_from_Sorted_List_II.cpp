//
// Created by Basti031 on 2019/11/19.
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
    ListNode *deleteDuplicates(ListNode *head) {

        if(head==NULL || head->next==NULL)
            return head;

        ListNode *p=head->next;

        if(p->val!=head->val){
            head->next=deleteDuplicates(p);
            return head;
        }
        else{
            while(p && p->val==head->val) p=p->next;
            return deleteDuplicates(p);
        }
    }
};

/*
int main() {

    ListNode n1 = ListNode(1);
    ListNode n2 = ListNode(1);
    ListNode n3 = ListNode(2);
    ListNode n4 = ListNode(3);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution solution = Solution();
    ListNode *head = solution.deleteDuplicates(&n1);
    int a = 1;

}*/
