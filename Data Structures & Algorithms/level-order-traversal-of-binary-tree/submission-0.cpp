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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode* > qu;
        qu.push(root);
        vector<vector<int>> res;
        while(!qu.empty()){
            int n=qu.size();
            vector<int> tmp;
            for(int i=0;i<n;i++){
                TreeNode* node = qu.front();
                qu.pop();
                tmp.push_back(node->val); 

                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
