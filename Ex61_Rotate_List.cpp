//
// Created by Basti031 on 2018/7/20.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

};


class Solution {
public:

    int length2(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        return len;
    }

    vector<ListNode *> getKey(ListNode *head, int index) {

        vector<ListNode *> v;

        ListNode *f = head;
        ListNode *s = head;

        for (int i = 0; i < index; ++i) {
            f = f->next;
        }

        while (f->next != NULL) {
            f = f->next;
            s = s->next;
        }
        v.push_back(f);
        v.push_back(s);
        return v;
    }

    ListNode *rotateRight(ListNode *head, int k) {

        int length = length2(head);
        if (length ==0){
            return head;
        }

        int index = k % length;
        if (index == 0) {
            return head;
        }

        vector<ListNode *> keys = getKey(head, index);

        ListNode *slow = keys[1];
        ListNode *fast = keys[0];

        ListNode *newStart = slow->next;
        ListNode *q = slow;

        while (slow->next) {
            slow = slow->next;
        }
        slow->next = head;
        q->next = NULL;

        return newStart;

    }

    ListNode *rotateRight2(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *p = head;
        //求链表的长度
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        k %= len;
        //k<=0时，原链表不旋转
        if (k <= 0)
            return head;
        int index = 1;
        //寻找右旋k位置后，链表的首结点
        p = head;
        while (index < (len - k) && p->next != NULL) {
            index++;
            p = p->next;
        }

        ListNode *ret = p->next, *q = p;

        //原链表寻找尾结点，将其链接到head
        while (p->next)
            p = p->next;
        p->next = head;

        //前部分尾结点设为NULL
        q->next = NULL;
        return ret;

    }

};
/*

int main() {
    ListNode n1 = ListNode(1);
*/
/*    ListNode n2 = ListNode(2);
    ListNode n3 = ListNode(3);
    ListNode n4 = ListNode(4);
    ListNode n5 = ListNode(5);*//*

*/
/*    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;*//*

    Solution solution = Solution();
    ListNode *s = solution.rotateRight(&n1, 1);
    int a = 1;
}
*/
