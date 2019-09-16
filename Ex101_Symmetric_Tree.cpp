//
// Created by Basti031 on 2018/10/23.
//
#include<iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isMirror(TreeNode *t1, TreeNode *t2) {

//        if (!t1 && !t2) {
//            return true;
//        }
//        if (!t1 || !t2) {
//            return false;
//        }
        if ( NULL==t1 )   return NULL==t2;
        if ( NULL==t2 )  return false;

        if (t1->val != t2->val) {
            return false;
        }

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root){
            return true;
        }
        return isMirror(root->left, root->right);
    }
};

/*
int main() {
    Solution solution = Solution();
    TreeNode s1 = TreeNode(1);
    TreeNode s2 = TreeNode(2);
    TreeNode s3 = TreeNode(2);
    TreeNode s4 = TreeNode(3);
    TreeNode s5 = TreeNode(4);
    TreeNode s6 = TreeNode(4);
    TreeNode s7 = TreeNode(3);
    s1.left = &s2;
    s1.right = &s3;
    s2.left = &s4;
    s2.right = &s5;
    s3.left = &s6;
    s3.right = &s7;
    bool result = solution.isSymmetric(&s1);
    cout << result;
}*/
