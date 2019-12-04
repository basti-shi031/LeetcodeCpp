//
// Created by Basti031 on 2019/12/4.
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
    TreeNode *getRootNode(vector<int> &nums, int start, int end) {

        if (start > end) {
            return NULL;
        }
        int middle = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = getRootNode(nums, start, middle - 1);
        root->right = getRootNode(nums, middle + 1, end);
        return root;
    }


    TreeNode *sortedArrayToBST(vector<int> &nums) {

        if (nums.size() == 0) {
            return NULL;
        }
        if (nums.size() == 1) {
            TreeNode* result = new TreeNode(nums[0]);
            return result;
        }

        int size = nums.size();
        TreeNode *root = getRootNode(nums, 0, size - 1);
        return root;
    }
};

int main() {
    Solution solution = Solution();
    vector<int> v;
    v.push_back(-10);
    v.push_back(-3);
    v.push_back(0);
    v.push_back(5);
    v.push_back(9);
    TreeNode *node = solution.sortedArrayToBST(v);
    int a = 1;
}

