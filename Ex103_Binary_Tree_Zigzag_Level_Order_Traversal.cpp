
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector <vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};
        vector <vector<int>> res;
        queue < TreeNode * > q{{root}};
        int cnt = 0;
        while (!q.empty()) {
            vector<int> oneLevel;
            for (int i = q.size(); i > 0; --i) {
                TreeNode *t = q.front();
                q.pop();
                oneLevel.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (cnt % 2 == 1) reverse(oneLevel.begin(), oneLevel.end());
            res.push_back(oneLevel);
            ++cnt;
        }
        return res;
    }
};