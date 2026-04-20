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
    pair<int,int> diameter(TreeNode* root){
        if(root == nullptr) return {0,0};
        pair<int,int> left = diameter(root->left);
        pair<int,int> right = diameter(root->right);

        int maxHeight = 1 + max(left.second,right.second);
        int maxDiameter = max(max(left.first,right.first), left.second + right.second + 1);

        return {maxDiameter, maxHeight};

    }

    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> getDiameter = diameter(root);
        return getDiameter.first-1;
    }
};
