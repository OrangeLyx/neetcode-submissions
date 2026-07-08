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
    private:int ans=INT_MIN;
    int find(TreeNode * node){
        if(node==nullptr) return 0;
        int val=node->val;
        int left=max(0,find(node->left));
        int right=max(0,find(node->right));
        ans=max(ans,left+right+val);
        return max(left,right)+val;
    }
public:
    int maxPathSum(TreeNode* root) {
        find(root);
        return ans;
    }
};
