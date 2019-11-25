//
// Created by Basti031 on 2019/11/25.
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

    void flatten(TreeNode *root) {

        if (root == NULL) return;


        if (root->left != NULL) {
            TreeNode *cur = root->left;
            while (cur->right != NULL) {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        flatten(root->right);
    }
};