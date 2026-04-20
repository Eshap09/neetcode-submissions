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
    bool checkValid(TreeNode* root, int minm, int maxm){
        if(root == nullptr) return true;
       
        bool left = checkValid(root->left, minm, root->val);
        bool right = checkValid(root->right, root->val, maxm);

        if(left && right && root->val >minm && root->val<maxm){
            return true;
        }
        else{
            return false;
        }

    }

    bool isValidBST(TreeNode* root) {
        int minm = INT_MIN;
        int maxm = INT_MAX;

        return checkValid(root, minm,maxm);
    }
};
