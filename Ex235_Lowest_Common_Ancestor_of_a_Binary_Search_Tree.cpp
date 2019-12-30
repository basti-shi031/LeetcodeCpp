//
// Created by Basti031 on 2019/12/18.
//


#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        int rootValue = root->val;
        int pValue = p->val;
        int qValue = q->val;

        if (pValue == rootValue || qValue == rootValue) {
            return root;
        }

        if (pValue > rootValue && qValue > rootValue) {
            return lowestCommonAncestor(root->right, p, q);
        } else if (pValue < rootValue && qValue < rootValue) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};