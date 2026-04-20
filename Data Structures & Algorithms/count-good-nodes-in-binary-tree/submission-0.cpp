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
    void traversal(TreeNode* root, int &count, int max){
        if(root == nullptr) return;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        traversal(root->left,count,max);
        traversal(root->right, count,max);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = -101;
        traversal(root, count, max);
        return count;
    }
};
