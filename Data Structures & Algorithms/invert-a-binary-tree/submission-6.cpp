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
    private: TreeNode* invert(TreeNode* head){
        if(head==nullptr) return head;
        TreeNode * left=invert(head->right);
        TreeNode * right=invert(head->left);
        head->left=left;
        head->right=right;
        return head;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return root;
        return invert(root);
    }
};
