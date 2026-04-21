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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preIdx,int start, int end, 
    unordered_map<int,int>mp){
        if(preIdx < 0 || preIdx >=preorder.size()){
            return nullptr;
        }
        if(start>end) return nullptr;
        int index = mp[preorder[preIdx]];
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        root->left = build(preorder,inorder, preIdx, start, index-1, mp);
        root->right = build(preorder,inorder, preIdx, index+1, end, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start =0;
        int end = preorder.size();
        int preIdx =0;
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder, inorder, preIdx, start,end-1, mp);
    }
};
