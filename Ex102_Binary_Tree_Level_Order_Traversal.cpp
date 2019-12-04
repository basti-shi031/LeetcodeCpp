//
// Created by Basti031 on 2019/12/4.
//




#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {

        vector <vector<int>> result;
        if (root == NULL) {
            return result;
        }

        queue < TreeNode * > q;
        q.push(root);

        int size = 1;
        while (!q.empty()) {

            vector<int> v;
            int count = 0;
            for (int i = size; i > 0; i--) {
                TreeNode *top = q.front();
                q.pop();
                v.push_back(top->val);

                TreeNode *left = top->left;
                TreeNode *right = top->right;

                if (left != NULL) {
                    q.push(left);
                    count++;
                }
                if (right != NULL) {
                    q.push(right);
                    count++;
                }
            }
            result.push_back(v);
            size = count;
        }
        return result;
    }
};

/*
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
    vector<vector<int>> v = solution.levelOrder(&node1);

    for (int i = 0; i < v.size(); ++i) {

        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl;

    }
}*/
