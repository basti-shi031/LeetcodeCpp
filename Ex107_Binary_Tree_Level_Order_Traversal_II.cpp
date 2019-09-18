//
// Created by Basti031 on 2019/9/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {

        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        vector<TreeNode> nodes;

        nodes.push_back(*root);

        while (nodes.size() != 0) {
            vector<int> nums;
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = nodes[i];
                if (node.left != NULL) {
                    nodes.push_back(*node.left);
                }
                if (node.right != NULL) {
                    nodes.push_back(*node.right);
                }

                nums.push_back(node.val);
            }
            result.push_back(nums);
            nodes.erase(nodes.begin(), nodes.begin() + size);
        }
        reverse(result.begin(), result.end());
        return result;


    }
};