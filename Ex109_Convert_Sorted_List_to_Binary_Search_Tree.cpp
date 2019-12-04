//
// Created by Basti031 on 2019/12/4.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        //利用fast 和 slow 指针 找到链表中点
        return build(head,NULL);
    }
    TreeNode* build(ListNode* start, ListNode* end)
    {
        if (start == end)
        {
            return NULL;
        }
        ListNode* fast = start;
        ListNode* slow = start;
        while (fast != end && fast->next != end)//注意第一次执行的时候end为NULL 没毛病。。
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);
        return node;
    }
};