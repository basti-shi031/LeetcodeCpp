//
// Created by Basti031 on 2019/12/4.
//


#include <iostream>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int depth(TreeNode *root) {

        if (root == NULL) {
            return 0;
        }

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        int delta = leftDepth - rightDepth;

        if (delta > 1 || delta < -1 || leftDepth == -1 || rightDepth == -1) {
            return -1;
        }

        return max(leftDepth, rightDepth) + 1;

    }

    bool isBalanced(TreeNode *root) {

        return depth(root) != -1;

    }


};