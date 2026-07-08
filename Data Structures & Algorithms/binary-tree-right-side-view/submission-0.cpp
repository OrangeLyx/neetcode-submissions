/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        deque<TreeNode*> q;
        q.push_back(root);
        vector<int> ans;
        while (!q.empty()) {
            int n = q.size();
            TreeNode* rightmost = nullptr;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop_front();
                if (i == 0) {
                    rightmost = node;
                }
                if (node->right)
                    q.push_back(node->right);
                if (node->left)
                    q.push_back(node->left);
            }
            if (rightmost)
                ans.push_back(rightmost->val);
        }

        return ans;
    }
};
