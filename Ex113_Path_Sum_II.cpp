//
// Created by Basti031 on 2019/11/25.
//
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {


public:

    void path(vector<int> &v, TreeNode *root, int sum, vector<vector<int>> &result) {

        if (!root) {
            return;
        }
        v.push_back(root->val);

        int target = sum - root->val;

        if (!root->left && !root->right) {
            if (target == 0) {
                result.push_back(v);
                v.pop_back();
                return;
            } else {
                v.pop_back();
                return;
            }
        }

        path(v, root->left, target, result);
        path(v, root->right, target, result);
        v.pop_back();
        return;
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum) {

        vector<vector<int>> result;
        vector<int> v;
        path(v, root, sum, result);

        return result;

    }
};