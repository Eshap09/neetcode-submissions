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
    pair<bool,int> calIsBal(TreeNode* root){
        if(root == nullptr) return {true,0};
        pair<bool, int> left = calIsBal(root->left);
        pair<bool, int> right = calIsBal(root->right);

        int maxHeight = 1 + max(left.second, right.second);

        if((abs(left.second - right.second) > 1) || !(left.first && right.first)){
            return {false, maxHeight};
        }
        else {
            return {true, maxHeight};
        }
    }

    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = calIsBal(root);
        return ans.first;

    }
};
