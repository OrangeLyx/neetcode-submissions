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
    private: bool isTrue(TreeNode* node, int mn, int mx){
        if(node==nullptr) return true;
        if(node->val >=mx || node->val<= mn) return false;
        return isTrue(node->left,mn,node->val) && isTrue(node->right,node->val,mx);
    }
public:
    bool isValidBST(TreeNode* root) {
        return isTrue(root,INT_MIN,INT_MAX);
    }
};
