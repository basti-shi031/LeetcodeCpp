//
// Created by Basti031 on 2018/10/23.
//
#include<iostream>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (!p ||!q) {
            return false;
        }
        //深度遍历
        stack<TreeNode *> s1, s2;
        s1.push(p);
        s2.push(q);
        while ((!s1.empty()) || (!s2.empty())) {
            if (s1.empty() || s2.empty()) {
                return false;
            }

            //比对当前节点
            TreeNode* s1Top = s1.top();
            TreeNode* s2Top = s2.top();

            if (!s1Top&& !s2Top) {
                s1.pop();
                s2.pop();
                continue;
            }

            if (!s1Top ||!s2Top) {
                return false;
            }

            if (s1Top->val != s2Top->val) {
                return false;
            }
            s1.pop();
            s2.pop();
            TreeNode* s1Right = s1Top->right;
            TreeNode* s1Left = s1Top->left;
            TreeNode* s2Right = s2Top->right;
            TreeNode* s2Left = s2Top->left;

            s1.push(s1Right);
            s1.push(s1Left);
            s2.push(s2Right);
            s2.push(s2Left);
        }
        return true;
    }
};

/*
int main() {
    Solution solution = Solution();
    TreeNode s1 = TreeNode(1);
    TreeNode r1 = TreeNode(1);
    bool result = solution.isSameTree(&s1, &r1);
    cout << result;
}*/
