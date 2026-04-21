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

class Codec {
public:
    void traversal(TreeNode* root,vector<int>&arr){
        if(root == nullptr) {
            arr.push_back(-101);
            return;
        }
        arr.push_back(root->val);
        traversal(root->left,arr);
        traversal(root->right,arr);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<int>arr;
        traversal(root, arr);
        string ans= "";
        for(int i=0;i<arr.size();i++){
            ans+= to_string(arr[i]) + ',';
        }
        ans.pop_back();
        cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    // NLR
    TreeNode* build(vector<string>nodes, int &i){
        if(nodes[i] == "-101"){
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i++]));
        root-> left = build(nodes, i);
        root->right = build(nodes, i);
        return root;
    }

    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        vector<string> nodes;
        string curr="";
        for(char c : data) {
            if(c == ',') {
                nodes.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        if(!curr.empty()) nodes.push_back(curr);
        
        int i = 0;
        return build(nodes, i);
    }
};
