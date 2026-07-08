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
private:
    int ans = 0;
    int getDiameter(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = getDiameter(root->left);
        int right = getDiameter(root->right);
        ans = std::max(ans, left + right);
        return std::max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);
        return ans;
    }
};
