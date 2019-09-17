//
// Created by Basti031 on 2019/9/17.
//
#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int maxDepth(TreeNode *root) {

        if (root == NULL) {
            return 0;
        }
        int depth = 0;
        vector<TreeNode> nodes;
        nodes.push_back(*root);
        while (nodes.size() != 0) {
            depth++;
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = nodes[i];
                if (node.left != NULL) {
                    nodes.push_back(*node.left);
                }
                if (node.right != NULL) {
                    nodes.push_back(*node.right);
                }
            }
            nodes.erase(nodes.begin(), nodes.begin() + size);
        }
        return depth;
    }
};

int main() {

    TreeNode node1 = TreeNode(3);
    TreeNode node2 = TreeNode(9);
    TreeNode node3 = TreeNode(20);
    TreeNode node4 = TreeNode(15);
    TreeNode node5 = TreeNode(7);

    node1.left = &node2;
    node1.right = &node3;

    node3.left = &node4;
    node3.right = &node5;

    Solution solution = Solution();

    int a = solution.maxDepth(&node1);

    cout << a;
    return 0;
}