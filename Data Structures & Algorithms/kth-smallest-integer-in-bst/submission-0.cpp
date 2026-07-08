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
    private: int ans=0;
    void find(TreeNode* node,int& k){
        if(node==nullptr) return;
        find(node->left,k);
        k--;
        if(k==0){
            ans=node->val; return;
        }
        find(node->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        find(root,k);
        return ans;
    }
};
