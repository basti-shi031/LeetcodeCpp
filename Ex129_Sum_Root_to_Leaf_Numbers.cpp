//
// Created by Basti031 on 2019/9/29.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        return sumNumbersDFS(root, 0);
    }
    int sumNumbersDFS(TreeNode *root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return sumNumbersDFS(root->left, sum) + sumNumbersDFS(root->right, sum);
    }
};

/*
int main() {
    TreeNode a(2);
    TreeNode b(3);
    TreeNode c(4);
    a.left = &b;
    a.right = &c;


    Solution solution = Solution();
    cout<<solution.sumNumbers(&a);
}*/
