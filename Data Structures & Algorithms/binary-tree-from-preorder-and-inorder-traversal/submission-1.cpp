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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndex;  
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        int preIdx = 0;  
        return build(preorder, inorder, inorderIndex, preIdx, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(const vector<int>& preorder,
                    const vector<int>& inorder,
                    const unordered_map<int, int>& inorderIndex,
                    int& preIdx, int inLeft, int inRight) {
        if (inLeft > inRight) return nullptr;

        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int idx = inorderIndex.at(rootVal);
        root->left = build(preorder, inorder, inorderIndex, preIdx, inLeft, idx - 1);
        root->right = build(preorder, inorder, inorderIndex, preIdx, idx + 1, inRight);

        return root;
    }
};

