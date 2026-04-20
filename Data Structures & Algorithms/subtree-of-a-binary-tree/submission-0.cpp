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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q) return false;
        if(!q && p) return false;
        if(!p && !q) return true;

        if(p->val == q->val){
            bool left = isSameTree(p->left, q->left);
            if(!left){
                return false;
            }
            bool right = isSameTree(p->right, q->right);
            if(!right){
                return false;
            }
            return true;
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!subRoot) return true;  
        if(!root) return false;  
        if(root->val == subRoot->val){
            if(isSameTree(root, subRoot)){
                return true;
            }
        }
        bool left = isSubtree(root->left, subRoot);
        if(left) return true;
        bool right = isSubtree(root->right, subRoot);
        if(right) return true;
        return false;
    }
};
