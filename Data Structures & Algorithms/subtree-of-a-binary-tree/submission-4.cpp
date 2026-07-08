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
    private: bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr) return q==nullptr;
        if(q==nullptr) return p==nullptr;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot==nullptr) return root==nullptr;
        if(root==nullptr && subRoot!=nullptr) return false;
        if(root->val==subRoot->val && isSameTree(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
