//
// Created by Basti031 on 2019/11/28.
//

#include <iostream>
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

    class TreeNodeWithLevel {
    public:
        TreeNode *treeNode;
        int level;
    };


    int minDepth(TreeNode *root) {

        if (!root) return 0;

        queue<TreeNodeWithLevel> q;
        TreeNodeWithLevel rootNode;
        rootNode.treeNode = root;
        rootNode.level = 1;
        q.push(rootNode);

        while (!q.empty()) {

            TreeNodeWithLevel frontNode = q.front();
            q.pop();

            if (frontNode.treeNode->left) {
                TreeNodeWithLevel tLeft;
                tLeft.treeNode = frontNode.treeNode->left;
                tLeft.level = frontNode.level + 1;
                q.push(tLeft);
            }
            if (frontNode.treeNode->right) {
                TreeNodeWithLevel tRight;
                tRight.treeNode = frontNode.treeNode->right;
                tRight.level = frontNode.level + 1;
                q.push(tRight);
            }
            if (!frontNode.treeNode->left && !frontNode.treeNode->right) {
                return frontNode.level;
            }

        }

        return 1;
    }
};

/*
int main() {

    Solution solution = Solution();

    TreeNode t1(1);
    TreeNode t2(2);
    t1.left = &t2;
    int a = solution.minDepth(&t1);

    cout << a;
}*/
